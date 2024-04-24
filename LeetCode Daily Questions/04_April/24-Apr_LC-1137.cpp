// https://leetcode.com/problems/n-th-tribonacci-number/description/?envType=daily-question&envId=2024-04-24

class Solution {
public:
    vector<int>dp;
    int f(int n){
        if (n==0){
            return 0;
        }
        if (n==1 || n==2){
            return 1;
        }
        if (dp[n]!=-1){
            return dp[n];
        }
        return dp[n] = f(n-1) + f(n-2) + f(n-3);
    }
    int tribonacci(int n) {
        dp.clear();
        dp.resize(40, -1);
        return f(n);
    }
};