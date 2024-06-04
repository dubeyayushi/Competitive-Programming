// https://leetcode.com/problems/string-to-integer-atoi/description/

class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        bool leadingWhitespace = true;
        bool leadingZeros = true;
        bool sign = true;
        bool negative = false;
        for (int i = 0; i<s.length(); i++){
            if (s[i]==' ' && leadingWhitespace){
                if (!sign) break;
                continue;
            }
            else if (s[i]=='0' && leadingZeros){
                if (i+1<s.length() && (s[i+1]<'0' || s[i+1]>'9')){
                    break;
                }
                continue;
            }
            else if (s[i]=='-' && sign){
                negative = true;
                sign = false;
            }
            else if (s[i]=='+' && sign){
                sign = false;
                continue;
            } 
            else if (s[i] >= '0' && s[i] <= '9') {
                int val = s[i] - '0';
                
                // Check for overflow
                if (ans > (INT_MAX - val) / 10) {
                    return negative ? INT_MIN : INT_MAX;
                }

                ans = ans * 10 + val;
                leadingZeros = false;
                sign = false;
                leadingWhitespace = false;
            }
            else{
                break;
            }
        }
        return negative ? -ans : ans;
    }
};