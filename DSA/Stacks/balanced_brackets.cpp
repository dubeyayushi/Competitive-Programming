#include<iostream>
#include<stack>
using namespace std;
 
bool balancedBrackets(string s){
    stack<char> st;
    if (s.length()%2!=0){
        return false;
    }
    for (int i = 0; i<s.size(); i++){
        if (s[i]=='('){
            st.push(s[i]);
        }
        else{
            if (st.size()==0){
                    return false;
            }
            else{
                st.pop();
            }
        }
    }
    if (st.size()==0){
        return true;
    }
    else{
        return false;
    }
}   

int main(){
    string s = "())()(";
    cout << balancedBrackets(s);
}