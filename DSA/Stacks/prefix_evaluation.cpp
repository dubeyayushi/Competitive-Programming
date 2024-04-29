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

int prefixEvaluation(string s){
    stack<int>val;
    for (int i = s.length()-1; i>=0; i--){
        if (s[i]>=48 && s[i]<=57){
            val.push(s[i]-48);
        }
        else{
            char ch = s[i];
            int val1 = val.top();
            val.pop();
            int val2 = val.top();
            val.pop();
            int ans = solve(val1, val2, ch);
            val.push(ans);
        }
    }
    return val.top();
    
}

int main(){
    string s = "-/*+79483";
    cout << prefixEvaluation(s) << endl;
}