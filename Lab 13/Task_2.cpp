#include<iostream>
#include<vector>
using namespace std;
int Firstnonrepat(vector<int>& v){
    vector<int> freq(2001, 0);
    for(int x:v){
        freq[x + 1000]++;
    }
    for(int x:v){
        if(freq[x+1000]==1){
            return x;
        }
    }
    return -1;
}
int main(){
    vector<int> v;
    vector<int> v1;
    v = {4, 5, 6, 7, 4, 6, 5, 6, 4, 5, 5, 6};
    v1 = {1, 5, 2, 5, 4, 1, 2, 3, 4, 3, 5};
    cout << "Non repeating " << Firstnonrepat(v);
    cout << endl;
    cout << "Non repeating " << Firstnonrepat(v1);
}
