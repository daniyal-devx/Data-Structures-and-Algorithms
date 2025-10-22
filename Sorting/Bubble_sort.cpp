#include<iostream>
#include<string>
using namespace std;
void Bubble_Sort(int *ar,int size){
    for (int i = 0; i < size - 1;i++){
        for (int j = 0; j < size - i - 1;j++){
            if (ar[j]>ar[j + 1]){
                int temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            }
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
    Bubble_Sort(ar, size);
    cout << "sorted array is :" << " ";
    for (int i = 0; i < size;i++){
        cout << ar[i] << " ";
    }
    delete[] ar;
    return 0;
}