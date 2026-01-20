#include<iostream>
#include<string>
#include "../LSLL.h"
using namespace std;
int main(){
    int size1;
    int size2;
    int n1;
    int n2;
    cout << "enter size for list 1";
    cin >> size1;
    cout << endl;
    cout << "enter size for list 2";
    cin >> size2;
    cout << endl;
    LSLL<int> result;
    LSLL<int> list01;
    LSLL<int> list02;
    for (int i = 0; i < size1;i++){
        cout << "enter a number for list 1" << " ";
        cin >> n1;
        list01.insertAtEnd(n1);
        cout << endl;
    }

    for (int i = 0; i < size2;i++){
        cout << "enter a number for list 2" << " ";
        cin >> n2;
        list01.insertAtEnd(n2);
        cout << endl;
    }
    cout << "list 01 is:" << " ";
    list01.display();
    cout << endl;
    cout << "list 02 is:" << " ";
    list02.display();
    cout << endl;
    result.combine(list01, list02);
    cout << "combined list is" << " ";
    result.display();
}