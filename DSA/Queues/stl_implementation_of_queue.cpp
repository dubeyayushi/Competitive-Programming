#include<iostream>
#include<queue>
#include<stack>
using namespace std;
 
void display(queue<int>&q){
    int n = q.size();
    for (int i = 0; i<n; i++){
        int x = q.front();
        cout << x << " ";
        q.pop();
        q.push(x);
    }
    cout << endl;
}

void reverse(queue<int>&q){
    stack<int>st;
    while(q.size()){
        st.push(q.front());
        q.pop();
    }
    while(st.size()){
        q.push(st.top());
        st.pop();
    }
}

int main(){
    queue<int>q;
    //push - happens only at the back O(1)
    //pop - only happens at front O(1)
    //front - we can access the front of the queue
    //back - we can also access the rear element
    //size - we can find the size of the queue
    //isempty() - returns true if queue is empty, false otherwise
    //overflow - only happens if we implement the queue via array if you fill the array or you are out of memory
    //underflow - whenever the queue is empty and we try t use these functions - pop(), front(), back()
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    display(q);
    reverse(q);
    display(q);

}