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

void pushElementAtIdx(stack<int>& st, int val, int idx){
    stack<int>temp;
    int count = 1;
    if (idx>=st.size()){
        cout << "Invalid index" << endl;
    }
    else{
        while(count<=idx){
            temp.push(st.top());
            st.pop();
            count++;
        }
        st.push(val);
        while(temp.size()>0){
            st.push(temp.top());
            temp.pop();
        }
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
    pushElementAtIdx(st, 60, 2);
    display(st);
}