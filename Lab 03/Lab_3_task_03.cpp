#include<iostream>
#include "Stack.h"
#include<string>
using namespace std;

int main() {
    cout << "enter a mathematical expression : ";
    string expression;
    getline(cin, expression);  
    Stack<char> brackets(100);  
    bool isValid = true;

    for(char c : expression) {
        if(c == '(' || c == '[' || c == '{') {
            brackets.push(c);
        }
        else if(c == ')' || c == ']' || c == '}') {
            if(brackets.isEmpty()) {
                isValid = false;
                break;
            }
            char lastBracket = brackets.pop();
            if((c == ')' && lastBracket != '(') ||
               (c == ']' && lastBracket != '[') ||
               (c == '}' && lastBracket != '{')) {
                isValid = false;
                break;
            }
        }
    }
    if(!brackets.isEmpty()) {
        isValid = false;
    }

    if(isValid) {
        cout << "The expression " << expression << " is good" << endl;
    } else {
        cout << "The expression " << expression << "is bad" << endl;
    }

    return 0;
}