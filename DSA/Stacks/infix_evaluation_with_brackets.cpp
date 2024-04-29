#include<iostream>
#include<stack>
using namespace std;
 
int priority(char ch){
    if (ch=='+' || ch=='-'){
        return 1;
    }
    else{
        return 2;
    }
}

int solve(int val1, int val2, char ch){
    int ans;
    if (ch=='+'){
        ans = val1 + val2;
    }
    else if (ch=='-'){
        ans = val1 - val2;
    }
    else if (ch == '/'){
        ans = val1 / val2;
    }
    else{
        ans = val1 * val2;
    }
    return ans;
}

int infix_solution(string s){
    stack<int>val;
    stack<char>op;
    for (int i = 0; i<s.length(); i++){
        if (s[i]>=48 && s[i]<=57){
            val.push(s[i]-48);
        }
        else{
            if (op.size()==0 || s[i]=='(' || op.top()=='('){
                op.push(s[i]);
            }
            else if (s[i]==')'){
                while(op.top()!='('){
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = solve(val1, val2, ch);
                    val.push(ans);
                }
                op.pop();
            }
            else if (priority(op.top())<priority(s[i])){
                op.push(s[i]);
            }
            else{
                while(op.size()>0 && priority(op.top())>=priority(s[i])){
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = solve(val1, val2, ch);
                    val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }
    while(op.size()>0){
        char ch = op.top();
        op.pop();
        int val2 = val.top();
        val.pop();
        int val1 = val.top();
        val.pop();
        int ans = solve(val1, val2, ch);
        val.push(ans);
    }
    return val.top();
}

int main(){
    string infix = "(7+9)*4/8-3";
    cout << infix_solution(infix) << endl;
}