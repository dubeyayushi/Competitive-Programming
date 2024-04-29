#include<iostream>
#include<stack>
using namespace std;
 
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
void pushAtBottomRecursively(stack<int>&st, int val){
    if (st.size()==0){
        st.push(val);
        return;
    }
    int x = st.top();
    st.pop();
    pushAtBottomRecursively(st, val);
    st.push(x);
}
void reverseRecursively(stack<int>&st){
    if (st.size()==1){
        return;
    }
    int x = st.top();
    st.pop();
    reverseRecursively(st);
    pushAtBottomRecursively(st, x);
}

int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    display(st);
    reverseRecursively(st);
    cout << endl;
    display(st);
}