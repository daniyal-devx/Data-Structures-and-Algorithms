#include <iostream>
#include "Stack.h"
#include<string>
#include<cctype>
using namespace std;
static const int maxsizecount = 100;
string reverseWords(const string& str){
    Stack<char> straight(str.length());
     Stack<char> reverse(str.length());
     string s2;
    char chr[maxsizecount];
    int count=0;
    for(char c:str){
        if(c==' '){
            count++;
        }
    }
    int j=0;
    for(int i=0;i<=count;i++){
            while(j<=str.length()){
            if(str[j]!=' '){
        straight.push(str[j]); 
        j++;
    }
     else
        {
            j++;
        break;
        }
    }
    while(!straight.isEmpty()){
        s2+=straight.pop();  
    }
    s2+=' ';
}

return s2;
}
int main(){
    string myname="Daniyal Usman";
cout<<reverseWords(myname);
return 0;
}