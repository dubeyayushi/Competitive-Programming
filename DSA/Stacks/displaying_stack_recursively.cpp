#include<iostream>
#include<stack>
using namespace std;
 
void displayRev(stack<int>&st){
    if (st.size()==0){
        return;
    }
    cout << st.top() << " ";
    int x = st.top();
    st.pop();
    displayRev(st);
    st.push(x);  
}

void display(stack<int>&st){
    if (st.size()==0){
        return;
    }
    int x = st.top();
    st.pop();
    display(st);
    st.push(x);  
    cout << x << " ";
}

int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    displayRev(st);
    cout << endl;
    display(st);
}