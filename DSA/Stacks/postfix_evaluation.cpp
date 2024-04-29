#include<iostream>
#include<stack>
using namespace std;
 
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

int postfixEvaluation(string s){
    stack<int>val;
    for (int i = 0; i<s.length(); i++){
        if (s[i]>=48 && s[i]<=57){
            val.push(s[i]-48);
        }
        else{
            char ch = s[i];
            int val2 = val.top();
            val.pop();
            int val1 = val.top();
            val.pop();
            int ans = solve(val1, val2, ch);
            val.push(ans);
        }
    }
    return val.top();
}

int main(){
    string postfix = "79+4*8/3-";
    int ans = postfixEvaluation(postfix);
    cout << ans << endl;
}