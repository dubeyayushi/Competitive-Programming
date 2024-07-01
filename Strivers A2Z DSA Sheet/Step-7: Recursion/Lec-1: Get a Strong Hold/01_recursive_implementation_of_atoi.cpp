// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int helper(string s, int idx, int ans, bool leadingWhitespace, bool leadingZeros, bool sign, bool negative){
        if (idx>=s.length()){
            return negative ? -ans : ans;
        }
        char curr = s[idx];
        if (leadingWhitespace && curr == ' '){
            return helper(s, idx+1, ans, true, leadingZeros, sign, negative);
        }
        if (leadingZeros && curr=='0'){
            if (idx+1 < s.length() && (s[idx+1] < '0' || s[idx+1] > '9')){
                return 0;
            }
            return helper(s, idx+1, ans, false, true, sign, negative);
        }
        if (sign){
            if (curr=='-'){
                return helper(s, idx+1, ans, false, false, false, true);
            }
            if (curr=='+'){
                return helper(s, idx+1, ans, false, false, false, false);
            }
        }
        if (curr >= '0' && curr <='9'){
            int val = curr - '0';
            if (ans > (INT_MAX-val)/10){
                return negative ? INT_MIN : INT_MAX;
            }
            ans = ans * 10 + val;
            return helper(s, idx+1, ans, false, false, false, negative);
        }
        return negative ? -ans : ans;
    }
    int myAtoi(string s) {
        return helper(s, 0, 0, true, false, true, false);
    }
};