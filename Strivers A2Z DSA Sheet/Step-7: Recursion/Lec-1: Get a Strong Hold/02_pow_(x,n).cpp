// https://leetcode.com/problems/powx-n/description/

class Solution {
public:
    double helper(double x, long n, double ans){
        if (n==0){
            return ans;
        }
        if (n%2==1){
            ans = ans * x;
            n = n-1;
        }
        else{
            x = x*x;
            n = n/2;
        }
        return helper(x, n, ans);
    }
    double myPow(double x, int n) {
        long nn = n;
        if (nn<0) nn = nn * -1;
        double ans = helper(x, nn, 1);
        if (n<0) ans = 1/ans;
        return ans;
    }
};