#include<iostream>
#include<queue>
#include<vector>
using namespace std;
 
int main(){
    priority_queue<int>maxpq;  //maxheap
    priority_queue<int, vector<int>, greater<int> >minpq;    //minheap
    minpq.push(3);
    minpq.push(4);
    minpq.push(11);
    minpq.push(9);
    minpq.push(-1);
    minpq.push(30);
    minpq.push(44);
    minpq.push(50);
    cout << minpq.top() << endl;


}