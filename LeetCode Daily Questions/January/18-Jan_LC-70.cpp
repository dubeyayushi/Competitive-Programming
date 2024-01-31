https://leetcode.com/problems/climbing-stairs/?envType=daily-question&envId=2024-01-18

class Solution {
public:
    vector<int>dp;
    int climbStairs(int n) {
        dp.clear();
        dp.resize(50, -1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};