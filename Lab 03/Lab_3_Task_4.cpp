#include<iostream>
#include "Stack.h"
#include<string>
#include<math.h>
#include<cmath>
using namespace std;
void addingLargeNumbers(string& input1,string& input2) 
{
    Stack<char> operandStack1(input1.length());
    Stack<char> operandStack2(input2.length());
    Stack<int> Result(50);
    for(char c : input1){
        if(isdigit(c)){
            operandStack1.push(c);
        }
    }
    for(char c: input2){
        if(isdigit(c)){
            operandStack2.push(c);
        }}
        int sum=0;
        int carry=0;
        for(int i=0;i<max(input1.length(),input2.length());i++){
           if(!operandStack1.isEmpty()&&!operandStack2.isEmpty()){
                 sum=(operandStack1.pop()-48)+(operandStack2.pop()-48)+carry;
                if(carry==1){
                    carry--;
                }
                if(sum>9){
                    sum=sum%10;
                    carry++;
                }
             }
              else if(operandStack1.isEmpty()){
                sum=(operandStack2.pop()-48)+carry;
                if(carry==1){
                    carry--;
                }
                if(sum>9){
                    sum=sum%10;
                    carry++;
                }
                
              }
              else if(operandStack2.isEmpty()){
                sum=(operandStack1.pop()-48)+carry;
                if(carry==1){
                    carry--;
                }
                if(sum>9){
                    sum=sum%10;
                    carry++;
                }
             
              }
              Result.push(sum);
        }
Result.displayStack();
}

int main(){
    string s1,s2;
    cout<<"Enter number 1 : ";
    getline(cin,s1);  
    cout<<"Enter number 2 : ";
    getline(cin,s2);
   addingLargeNumbers(s1,s2);
    return 0;
}