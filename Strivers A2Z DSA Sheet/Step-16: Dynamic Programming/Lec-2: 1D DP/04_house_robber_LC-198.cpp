// https://leetcode.com/problems/house-robber/description/

class Solution {
public:
    vector<int>dp;
    int solve(vector<int>&nums, int idx){
        if (idx==nums.size()-1){
            return dp[idx] = nums[idx];
        }
        if (idx==nums.size()-2){
            return dp[idx] = max(nums[idx], nums[idx+1]);
        }
        if (dp[idx]!=-1) return dp[idx];
        return dp[idx] = max(nums[idx] + solve(nums, idx+2), 0 + solve(nums, idx+1));
    }
    int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(nums.size()+1, -1);
        return solve(nums, 0);
    }
};