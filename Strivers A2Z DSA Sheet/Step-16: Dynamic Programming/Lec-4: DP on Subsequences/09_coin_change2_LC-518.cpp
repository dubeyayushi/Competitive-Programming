// https://leetcode.com/problems/coin-change-ii/description/

class Solution {
public:
    vector<vector<int>>dp;
    int solve(int amount, vector<int>&coins, int idx){
        if (amount==0){
            return 1;
        }
        if (idx==coins.size() || amount<0){
            return 0;
        }
        if (dp[idx][amount]!=-1) return dp[idx][amount];
        return dp[idx][amount] = solve(amount, coins, idx+1) + solve(amount-coins[idx], coins, idx);
    }
    int change(int amount, vector<int>& coins) {
        dp.clear();
        dp.resize(coins.size()+1, vector<int>(amount+1, -1));
        return solve(amount, coins, 0);
    }
};