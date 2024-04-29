#include<iostream>
#include<stack>
using namespace std;
 
string solve(string val1, string val2, char ch){
    string ans = "";
    ans.push_back(ch);
    ans += val1 + val2;
    return ans;
}

string postfixToPrefix(string s){
    stack<string>val;
    for (int i = 0; i<s.length(); i++){
        if (s[i]>=48 && s[i]<=57){
            val.push(to_string(s[i]-48));
        }
        else{
            char ch = s[i];
            string val2 = val.top();
            val.pop();
            string val1 = val.top();
            val.pop();
            string ans = solve(val1, val2, ch);
            val.push(ans);
        }
    }
    return val.top();
}

int main(){
    string s = "79+4*8/3-";
    cout << postfixToPrefix(s) << endl;
}