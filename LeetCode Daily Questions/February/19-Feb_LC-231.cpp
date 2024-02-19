// https://leetcode.com/problems/power-of-two/description/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n==0) return false;
        while(n){
            if (n==1){
                return true;
            }
            if (n%2==0){
                n = n/2;
            }
            else{
                return false;
            }
        }
        return true;
    }
};