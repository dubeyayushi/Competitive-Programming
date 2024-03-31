https://leetcode.com/problems/maximum-odd-binary-number/description/?envType=daily-question&envId=2024-02-23

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int zeros = 0;
        int ones = 0;
        for (int i = 0; i<s.length(); i++){
            if (s[i]=='1'){
                ones++;
            }
            else{
                zeros++;
            }
        }
        int i = 0;
        while(ones>1){
            s[i] = '1';
            i++;
            ones--;
        }
        while(zeros>0){
            s[i] = '0';
            i++;
            zeros--;
        }
        s[i] = '1';
        return s;
    }
};