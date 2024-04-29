#include<iostream>
#include<stack>
using namespace std;
 
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
    pushAtBottomRecursively(st, 100);
    display(st);
    
}