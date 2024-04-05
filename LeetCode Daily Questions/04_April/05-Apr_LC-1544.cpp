// https://leetcode.com/problems/make-the-string-great/description/

class Solution {
public:
    string makeGood(string s) {
        int originalLength = s.length();
        string ans = "";
        int newLength = ans.length();
        stack<char>st;
        for (int i = 0; i<s.length(); i++){
            st.push(s[i]);
        }
        while(!st.empty()){
            char first = st.top();
            cout << "first: " << first << endl;
            st.pop();
            if (st.empty()){
                ans = string(1, first) + ans;
            }
            else{
                char second = st.top();
                cout << "second: " << second << endl;
                if (abs(first-second)!=32){
                    ans = string(1, first) + ans;
                    cout << "ans: " << ans << endl;
                }
                else{
                    st.pop();
                }
            }
            if (st.empty()){
                newLength = ans.length();
                if (originalLength==newLength){
                    break;
                }
                else{
                    originalLength = ans.length();
                    for (int k = 0; k<ans.length(); k++){
                        st.push(ans[k]);
                    }
                    ans = "";
                }
            }
        }
        return ans;
    }
};