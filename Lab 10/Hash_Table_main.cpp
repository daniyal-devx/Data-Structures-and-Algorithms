#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

class HashTable {
private:
    string* table;
    int S;
    int n;

public:
    HashTable(int size) {
        S = size;
        n = 0;
        table = new string[S];
        for (int i = 0; i < S; i++) {
            table[i] = "";
        }
    }

    ~HashTable() {
        delete[] table;
    }

    bool isEmpty() {
        return n == 0;
    }

    bool isFull() {
        return n == S;
    }

    double loadFactor() {
        return (double)n / S;
    }

    int getHashValue(string name) {
        int sum = 0;
        for (char c : name) {
            sum += (int)c;
        }
        return sum % S;
    }

    bool insert(string name) {
        if (isFull()) return false;

        int index = getHashValue(name);
        cout << "Traverse sequence: " << index;

        while (table[index] != "") {
            index = (index + 1) % S;
            cout << " -> " << index;
        }

        cout << endl;
        table[index] = name;
        n++;
        return true;
    }

    bool search(string name) {
        int index = getHashValue(name);
        cout << "Traverse sequence: " << index;

        int start = index;
        while (table[index] != "") {
            if (table[index] == name) {
                cout << "found" << endl;
                return true;
            }
            index = (index + 1) % S;
            cout << " -> " << index;
            if (index == start) break;
        }
        cout << "not found" << endl;
        return false;
    }

    bool remove(string name) {
        int index = getHashValue(name);
        int start = index;

        while (table[index] != "") {
            if (table[index] == name) {
                table[index] = "";
                n--;
                return true;
            }
            index = (index + 1) % S;
            if (index == start) break;
        }
        return false;
    }
    void display() {
        for (int i = 0; i < S; i++) {
            if (table[i] == "") {
                cout << i << ": empty" << endl;
            } else {
                cout << i << ": " << table[i] << endl;
            }
        }
    }
};

int getRandomNumber(int start, int end) {
    return rand() % (end - start + 1) + start;
}

int experiment(int tableSize) {
    bool* available= new bool[tableSize];
    int count = 0;
    while (true) {
        int num = getRandomNumber(1, 100);
        int index = num % tableSize;
        if (available[index]) {
            delete[] available;
            return count;
        }
        available[index] = true;
        count++;
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    int size;
    cout << "Enter the size of Hash Table: ";
    cin >> size;

    HashTable ht(size);
    int choice;
    string name;

    do {
        cout << "1. Insert a name\n2. Search for a name\n3. Remove a name\n4. Display the Hash Table\n5. Display Load Factor of the table\n6. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name to insert: ";
                cin >> name;
                if (ht.insert(name)) {
                    cout << "Inserted successfully.\n";
                } else {
                    cout << "Insertion failed.\n";
                }
                break;
            case 2:
                cout << "Enter name to search: ";
                cin >> name;
                if (ht.search(name)) {
                    cout << "Found.\n";
                } else {
                    cout << "Not found.\n";
                }
                break;
            case 3:
                cout << "Enter name to remove: ";
                cin >> name;
                if (ht.remove(name)) {
                    cout << "Removed successfully.\n";
                } else {
                    cout << "Not found.\n";
                }
                break;
            case 4:
                ht.display();
                break;
            case 5:
                cout << "Load Factor: " << ht.loadFactor() << endl;
                break;
            case 6:
                cout << "Exiting.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    const int numExperiments = 50;
    cout << "Table Size\tAverage Inserted\n";
    cout << "----------\t----------------\n";

    for (int S = 10; S <= 100; S += 10) {
        double totalInserted = 0.0;

        for (int i = 0; i < numExperiments; i++) {
            totalInserted += experiment(S);
        }

        double averageInserted = totalInserted / numExperiments;
        cout << S << "\t\t" << fixed << setprecision(2) << averageInserted << endl;
    }

    return 0;
}