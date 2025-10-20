#include<iostream>
#include<string>
using namespace std;
bool Binary_Search(int *ar,int size,int value){
    int start = 0;
    int end = size - 1;
    while(start<=end){
        int mid = (start + end) / 2;
        if(ar[mid]==value){
        return true;
    }
        else if(ar[mid]<value){
            start = mid + 1;
        }
        else{
            end = end - 1;
        }
    }
    return false;
}
int main(){
    int size;
    cout << "enter size of array" << " ";
    cin >> size;
    int* ar = new int[size];
    cout << "enter elements of sorted array" << " ";
    for (int i = 0; i < size;i++){
        cin >> ar[i];
    }
    int value;
    cout << "enter value to be searched" << " ";
    cin >> value;
    bool found = Binary_Search(ar, size, value);
    if (found){
        cout << "value found";
    }
    else{
        cout << "value not found";
    }
    delete[] ar;
    return 0;
}