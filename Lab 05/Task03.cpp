#include<iostream>
#include<string>
#include<vector>
using namespace std;
int countWays(int numStairs){
    if(numStairs < 0) 
    return 0;
    if(numStairs <= 1) 
    return 1;
    
    return countWays(numStairs-1) + countWays(numStairs-2);
}
int main(){
    cout << "no of ways for 4 stairs :"<<countWays(4)<<endl;
    cout << "no of ways for 3 stairs:"<<countWays(3)<<endl;
    cout << "no of ways for 7 stairs:"<<countWays(7)<<endl;
    return 0;
}