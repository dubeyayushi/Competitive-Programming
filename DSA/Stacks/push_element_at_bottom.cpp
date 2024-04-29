#include<iostream>
#include<stack>
using namespace std;
 
void display(stack<int>st){
    stack<int>temp;
    while(st.size()>0){
        cout << st.top() << " ";
        temp.push(st.top());
        st.pop();
    }
    while(temp.size()>0){
        st.push(temp.top());
        temp.pop();
    }
    cout << endl;
}

void pushElementAtBottom(stack<int>& st, int val){
    stack<int>temp;
    while(st.size()>0){
        temp.push(st.top());
        st.pop();
    }
    st.push(val);
    while(temp.size()>0){
        st.push(temp.top());
        temp.pop();
    }
}

int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    display(st);
    pushElementAtBottom(st, 60);
    display(st);
}