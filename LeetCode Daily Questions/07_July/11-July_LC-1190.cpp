// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/?envType=daily-question&envId=2024-07-11

class Solution {
public:
    string reverseParentheses(string s) {
        string str = "";
        stack<string>st;
        for (int i = 0; i<s.length(); i++){
            if (s[i]=='('){
                st.push(str);
                str = "";
            }
            else if (s[i]==')'){
                reverse(str.begin(), str.end());
                str = st.top() + str;
                st.pop();
            }
            else{
                str += s[i];
            }
        }
        return str;
    }
};