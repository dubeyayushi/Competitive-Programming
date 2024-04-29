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

void reverse(stack<int>st){
    stack<int>temp1;
    stack<int>temp2;
    while(st.size()>0){
        temp1.push(st.top());
        st.pop();
    }
    while(temp1.size()>0){
        temp2.push(temp1.top());
        temp1.pop();
    }
    while(temp2.size()>0){
        st.push(temp2.top());
        temp2.pop();
    }
    display(st);
}

int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    display(st);
    reverse(st);
    
}