#include<iostream>
#include<string>
using namespace std;
bool Linear_Search(int *ar,int size,int value){
    for (int i = 0; i < size;i++){
        if (ar[i]==value){
            return true;
        }
    }
    return false;
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
    int value;
    cout << "enter value to be searched" << " ";
    cin >> value;
    bool found = Linear_Search(ar, size, value);
    if (found){
        cout << "value found";
    }
    else{
        cout << "value not found";
    }
    delete[] ar;
    return 0;
}