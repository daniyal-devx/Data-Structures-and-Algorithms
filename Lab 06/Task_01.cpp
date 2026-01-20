#include<iostream>
#include<string>
#include "../LSLL.h"
using namespace std;
int main(){
    LSLL<int> listinteger;
    int n;
    for (int i = 0; i < 5;i++){
        cout << "enter a number" << " ";
        cin >> n;
        listinteger.insertAtEnd(n);
        cout << endl;
    }
    listinteger.display();
    int value = 0;
    listinteger.removeKthNode(4, value);
    listinteger.display();
    cout << endl;
    cout << "and value is :" << value;
}