// https://leetcode.com/problems/perfect-squares/description/

class Solution {
public:
    vector<int>dp;
    int f(int n){
        if (n==0){
            return 0;
        }
        if (n<0){
            return INT_MAX;
        }
        if (dp[n]!=-1){
            return dp[n];
        }
        int ans = INT_MAX;
        for (int i = 1; i*i<=n; i++){
            ans = min(ans, 1+f(n-(i*i)));
        }
        return dp[n] = ans;
    }
    int numSquares(int n) {
        dp.clear();
        dp.resize(n+1, -1);
        return f(n);
    }
};