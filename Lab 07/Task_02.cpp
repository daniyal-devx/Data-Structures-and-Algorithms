#include<iostream>
#include<string>
#include "../CDLL.h"
using namespace std;
int main(){
    CDLL<int> list1;
    CDLL<int> list2;
    CDLL<int> list3;
    int n;
    int size1;
    cout << "enter size of list1" << endl;
    cin >> size1;
    cout << "enter numbers for list1";
    for (int i = 0; i < size1; i++)
    {
        cin >> n;
        list3.insertAtEnd(n);
    }
    cout << "before splitting" << endl;
    list3.display();
    list3.splitList(list1, list2);
    cout <<"after spliting";
    list1.display();
    list2.display();
}
