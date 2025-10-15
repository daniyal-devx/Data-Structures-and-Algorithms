#include<iostream>
#include "Stack.h"
#include<string>
#include<cctype>
using namespace std;

string cleanString(const string& input) {
    string cleaned;
    for(char c : input) {
        if(isalnum(c)) {
            cleaned += tolower(c);
        }
    }
    return cleaned;
}
int main() {
    cout << "enter a string to check palindrome ";
    string input;
    getline(cin, input);
    
    string cleaned = cleanString(input);
    Stack<char> s1(cleaned.length());
    
    for(char c : cleaned) {
        s1.push(c);
    }
    
    if(s1.isPalindrome()) {
        cout  << input << "is a palindrome " << endl;
    } else {
        cout  << input << "is not a palindrome." << endl;
    }
    
    return 0;
}

    /*static const int maxsizecount = 100;
    char chr[maxsizecount];
    for (int i = 0; i < s1.length(); i++) {
        chr[i] = s1[i];
    }
    int count = 1;
    bool palindrome = true;
    for (int i = 0; i < s1.length(); i++) {
        if (chr[i] == chr[s1.length() - count]) {
            palindrome = false;
        }
        count++;
    }*/