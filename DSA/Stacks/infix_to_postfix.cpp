#include<iostream>
#include<stack>
using namespace std;
 
string solve(string val1, string val2, char ch){
    string ans = "";
    ans += val1 + val2;
    ans.push_back(ch);
    return ans;
}

int priority(char ch){
    if (ch=='+' || ch=='-'){
        return 1;
    }
    else{
        return 2;
    }
}

string infixToPrefix(string s){
    stack<string>val;
    stack<char>op;
    for (int i = 0; i<s.length(); i++){
        if (s[i]>=48 && s[i]<=57){
            val.push(to_string(s[i]-48));
        }
        else if (op.size()==0 || s[i]=='(' || op.top()=='('){
            op.push(s[i]);
        }
        else if (s[i]==')'){
                while(op.top()!='('){
                    char ch = op.top();
                    op.pop();
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop();
                    string ans = solve(val1, val2, ch);
                    val.push(ans);
                }
                op.pop();
            }
        else if (priority(s[i])>priority(op.top())){
            op.push(s[i]);
        }
        else{
            while(op.size()>0 && priority(s[i])<=priority(op.top())){
                char ch = op.top();
                op.pop();
                string val2 = val.top();
                val.pop();
                string val1 = val.top();
                val.pop();
                string ans = solve(val1, val2, ch);
                val.push(ans);
            }
            op.push(s[i]);
        }
    }
    while(op.size()>0){
        char ch = op.top();
        op.pop();
        string val2 = val.top();
        val.pop();
        string val1 = val.top();
        val.pop();
        string ans = solve(val1, val2, ch);
        val.push(ans);
    }
    return val.top();
}

int main(){
    string infix = "(7+9)*4/8-3";
    string prefix = infixToPrefix(infix);
    cout << prefix << endl;
}