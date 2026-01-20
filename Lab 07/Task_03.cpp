#include<iostream>
#include<string>
#include "../CDLL.h"
using namespace std;
int main(){
    CDLL<int> list1;
    CDLL<int> list2;
    CDLL<int> list3;
    int n;
    int size1, size2;
    cout << "enter size of list1" << endl;
    cin >> size1;
    cout << "enter size of list2" << endl;
    cin >> size2;
    cout << "enter numbers for list1";
    for (int i = 0; i < size1; i++)
    {
        cin >> n;
        list1.insertAtEnd(n);
    }
    cout << "enter numbers for list2";
    for(int i = 0; i < size2; i++)
    {
        cin >> n;
        list2.insertAtEnd(n);
    }
    list3.combine(list1, list2);
    cout <<"after combining";
    list3.display();
    list3.clear();
    cout << "enter size of list1" << endl;
    cin >> size1;
    cout << "enter size of list2" << endl;
    cin >> size2;
    cout << "enter numbers for list1";
    for (int i = 0; i < size1; i++)
    {
        cin >> n;
        list1.insertAtEnd(n);
    }
    cout << "enter numbers for list2";
    for(int i = 0; i < size2; i++)
    {
        cin >> n;
        list2.insertAtEnd(n);
    }
    list3.shuffleMerge(list1, list2);
    cout <<"after shuffle merge";
    list3.display();

}
