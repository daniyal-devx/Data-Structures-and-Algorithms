#include <iostream>
#include "Queue.h"
#include "Queue.cpp"
#include<string>
#include<vector>
#include<cctype>
using namespace std;

int timeRequiredToBuy(vector<int>& tickets, int k) {
    int n = tickets.size();
    Queue<int> q(n);
    
    // Add all people to the queue
    for(int i = 0; i < n; i++) {
        q.enqueue(i);
    }
    
    int time = 0;
    
    // Continue until person k buys all their tickets
    while(tickets[k] > 0) {
        // Get next person in line
        int currentPerson = q.getFront();
        q.dequeue();
        
        // This person buys one ticket
        tickets[currentPerson]--;
        time++;
        
        // If this person still needs tickets, send to back of line
        if(tickets[currentPerson] > 0) {
            q.enqueue(currentPerson);
        }
    }
    
    return time;
}

int main()
{
vector<int> tickets={2,3,2};
int k=2;
cout<<"time is :"<<timeRequiredToBuy(tickets,k);
vector<int> tickets2 = {5, 1, 1, 1};
    int k2 = 0;
    cout<<endl<<"time is :"<<timeRequiredToBuy(tickets2,k2);
    
    
    return 0;
return 0;

}