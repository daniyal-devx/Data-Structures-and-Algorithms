#include<iostream>
#include<string>
#include "../LSLL.h"
using namespace std;
int main()
{
    LSLL<int> result;
    int n1;
    for (int i = 0; i < 5;i++){
        cout << "enter a number for list 1" << " ";
        cin >> n1;
        result.insertAtEnd(n1);
        cout << endl;
    }
    cout << "original list :" << " ";
    result.display();
    result.reverse();
    cout << "reversed list: " << " ";
    result.display();
    return 0;
}
