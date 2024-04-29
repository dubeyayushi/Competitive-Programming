#include<iostream>
#include<stack>
using namespace std;
 
string solve(string val1, string val2, char ch){
    string ans = "";
    ans += val1 + val2;
    ans.push_back(ch);
    return ans;
}

string prefixToPostfix(string s){
    stack<string>val;
    for (int i = s.length()-1; i>=0; i--){
        if (s[i]>=48 && s[i]<=57){
            val.push(to_string(s[i]-48));
        }
        else{
            char ch = s[i];
            string val1 = val.top();
            val.pop();
            string val2 = val.top();
            val.pop();
            string ans = solve(val1, val2, ch);
            val.push(ans);
        }
    }
    return val.top();
}

int main(){
    string s = "-/*+79483";
    cout << prefixToPostfix(s) << endl;
}