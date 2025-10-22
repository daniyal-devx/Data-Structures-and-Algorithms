#include<iostream>
#include<string>
using namespace std;
void Selection_Sort(int *ar,int size){
    for (int i = 0; i < size - 1;i++){
        int min_index = i;
        for (int j = i + 1; j < size;j++){
            if (ar[j]<ar[min_index]){
                min_index = j;
            }
        }
        if (min_index != i){
            int temp = ar[i];
            ar[i] = ar[min_index];
            ar[min_index] = temp;
        }
    }
}

int main(){
    int size;
    cout << "enter size of array" << " ";
    cin >> size;
    int* ar = new int[size];
    cout << "enter elements of array" << " ";
    for (int i = 0; i < size;i++){
        cin >> ar[i];
    }
    Selection_Sort(ar, size);
    cout << "sorted array is :" << " ";
    for (int i = 0; i < size;i++){
        cout << ar[i] << " ";
    }
    delete[] ar;
    return 0;
}