#include<iostream>
#include<queue>
#include<stack>
using namespace std;
 
void reorderQueue(queue<int>&q){
    stack<int>st;
    int n = q.size();
    //reverse first half
    for (int i = 0; i<n/2; i++){
        st.push(q.front());
        q.pop();
    }
    while(st.size()){
        q.push(st.top());
        st.pop();
    }
    //add second half in stack
    for (int i = 0; i<n/2; i++){
        st.push(q.front());
        q.pop();
    }
    while(st.size()){
        q.push(st.top());
        q.push(q.front());
        st.pop();
        q.pop();
    }
    while(q.size()){
        st.push(q.front());
        q.pop();
    }
    while(st.size()){
        q.push(st.top());
        cout << st.top() << " ";
        st.pop();
    }
    
}

int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    reorderQueue(q);
}