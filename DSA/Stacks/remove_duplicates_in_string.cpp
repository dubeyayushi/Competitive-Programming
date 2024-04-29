#include<iostream>
#include<stack>
#include<string>
using namespace std;
 
string removeDuplicates(string s){
    stack<char>st;
    st.push(s[0]);
    for (int i = 1; i<s.length(); i++){
        if (s[i]!=st.top()){
            st.push(s[i]);
        }
    }
    s = "";
    while(st.size()){
        s += st.top();
        st.pop();
    }
    return s;
}

int main(){
    string s = "aaabbcddaabffg";
    s = removeDuplicates(s);
    for (int i = s.length()-1; i>=0; i--){
        cout << s[i];
    }
    cout << endl;
}