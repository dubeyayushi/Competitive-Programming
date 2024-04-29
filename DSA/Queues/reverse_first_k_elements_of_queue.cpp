#include<iostream>
#include<queue>
#include<stack>
using namespace std;
 
void reverseKElements(queue<int>&q, int k){
    if (k>q.size()){
        return;
    }
    int count = 0;
    stack<int>st;
    while(count<k){
        st.push(q.front());
        q.pop();
        count++;
    }
    while(st.size()){
        q.push(st.top());
        st.pop();
    }
    count = q.size()-k;
    for (int i = 0; i<count; i++){
        q.push(q.front());
        q.pop();
    }
}
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

int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    display(q);
    reverseKElements(q, 2);
    display(q);
}