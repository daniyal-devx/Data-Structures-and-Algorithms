#include<iostream>
#include<string>
using namespace std;
void Insertion_Sort(int *ar,int size){
    for (int i = 1; i < size;i++){
        int key = ar[i];
        int j = i - 1;
        while (j >= 0 && ar[j]>key){
            ar[j + 1] = ar[j];
            j = j - 1;
        }
        ar[j + 1] = key;
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
    Insertion_Sort(ar, size);
    cout << "sorted array is :" << " ";
    for (int i = 0; i < size;i++){
        cout << ar[i] << " ";
    }
    delete[] ar;
    return 0;
}