#include <iostream>
#include <stdexcept>
using namespace std;

class D2_Array {
private:
    int* arr;
    int rows;
    int cols;
    int size;

public:
    D2_Array(int r, int c) : rows(r), cols(c), size(r* c) {
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }

    ~D2_Array() {
        delete[] arr;
    }

    D2_Array(const D2_Array& other) : rows(other.rows), cols(other.cols), size(other.size) {
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    int getIndexValue(int i, int j) {
        return arr[j * rows + i];
    }

    void setIndexValue(int i, int j, int val) {
        arr[j * rows + i] = val;
    }

    size_t addressOfIndex(int i, int j, size_t StartIndex) {
        int index = j * rows + i;
        return StartIndex + (index * sizeof(int));
    }

    D2_Array operator+(const D2_Array& other) {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrix dimensions must match");
        }

        D2_Array result(rows, cols);
        for (int i = 0; i < size; i++) {
            result.arr[i] = arr[i] + other.arr[i];
        }
        return result;
    }

    void printArray() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << getIndexValue(i, j) << "\t";
            }
            cout << endl;
        }
    }

    void printSubArray(int r1, int r2, int c1, int c2) {
        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                cout << getIndexValue(i, j) << "\t";
            }
            cout << endl;
        }
    }

    void clear(int m, int n, int value = 0) {
        for (int i = m; i <= n; i++) {
            for (int j = m; j <= n; j++) {
                if (i < rows && j < cols) {
                    setIndexValue(i, j, value);
                }
            }
        }
    }
};

int main() {
    D2_Array d1(3, 4);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            d1.setIndexValue(i, j, i * 4 + j + 1);
        }
    }
    cout << "Original array:" << endl;
    d1.printArray();

    cout << "\nSubarray [1:2, 1:3]:" << endl;
    d1.printSubArray(1, 2, 1, 3);

    return 0;
}
