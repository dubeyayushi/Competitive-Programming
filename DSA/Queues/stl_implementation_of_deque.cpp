#include<iostream>
#include<deque>
using namespace std;
 
int main(){
    deque<int>dq;
    dq.push_back(50);
    cout << dq.front() << endl;
}