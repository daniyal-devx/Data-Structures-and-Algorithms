#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void allocateArray(int***& arr, int n = 3) {
    arr = new int** [n];
    for (int i = 0; i < n; i++) {
        *(arr + i) = new int* [n];
        for (int j = 0; j < n; j++) {
            *(*(arr + i) + j) = new int[n];
        }
    }
}
void initializeArray(int*** arr, int n = 3) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                *(*(*(arr + i) + j) + k) = rand() % 100 + 1;
            }
        }
    }
}

void printArray(int*** arr, int n = 3) {
    cout << "3D Array:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cout << *(*(*(arr + i) + j) + k) << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void deallocateArray(int***& arr, int n = 3) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            delete[] * (*(arr + i) + j);
        }
        delete[] * (arr + i);
    }
    delete[] arr;
    arr = nullptr;
}

int main() {
    srand(time(0));
    int*** myarray = nullptr;
    allocateArray(myarray, 3);
    initializeArray(myarray, 3);
    printArray(myarray, 3);
    deallocateArray(myarray, 3);
    return 0;
}