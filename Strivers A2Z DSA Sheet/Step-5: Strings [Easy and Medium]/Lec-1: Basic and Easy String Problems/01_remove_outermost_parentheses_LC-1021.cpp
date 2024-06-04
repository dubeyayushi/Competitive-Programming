// https://leetcode.com/problems/remove-outermost-parentheses/description/

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string ans = "";
        int close = 0;
        for (int i = s.length()-1; i>=0; i--){
            if (close==0 && s[i]==')'){
                close++;
            }
            else if (s[i]=='(' && close==1){
                close--;
            }
            else if (s[i]=='('){
                close--;
                st.push('(');
            }
            else{
                close++;
                st.push(')');
            }
        }
        while(!st.empty()){
            char ch = st.top();
            st.pop();
            ans += ch;
        }
        return ans;
    }
};