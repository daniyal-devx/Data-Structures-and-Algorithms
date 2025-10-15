#include <iostream>
#include "Stack.h"
#include <string>
#include <cctype>
using namespace std;
bool isanbn(const string &str)
{
    Stack<char> s(100);
    int i = 0;
    while(i < str.length() && str[i] == 'a')
    {
        s.push('a');
        i++;
    }
    while (i < str.length() && str[i] == 'b')
    {
        if (s.isEmpty())
            return false;
        s.pop();
        i++;
    }
    return (i == str.length() && s.isEmpty());
}

int main()
{
    string input;
    cout << "enter string ";
    cin >> input;

    if (isanbn(input))
        cout << "string is of form";
    else
        cout << "not of form ";

        
    return 0;
}