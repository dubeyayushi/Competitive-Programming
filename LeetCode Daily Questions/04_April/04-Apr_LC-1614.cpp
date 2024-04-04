// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int ans = 0;
        int count = 0;
        for (int i = 0; i<s.length(); i++){
            if (s[i]=='('){
                count++;
                st.push(s[i]);
            }
            if (s[i]==')'){
                ans = max(ans, count);
                count--;
                st.pop();
            }
        }
        return ans;
    }
};