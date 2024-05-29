// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/

class Solution {
public:
    int numSteps(string s) {
        int n = s.length();
        int steps = 0;
        int carry = 0;
        for (int i = n-1; i>0; i--){
            int digit = s[i] - '0';
            if (digit + carry == 1){
                steps += 2;
                carry = 1;
            }
            else{
                steps += 1;
            }
        }
        steps += carry;
        return steps;
    }
};