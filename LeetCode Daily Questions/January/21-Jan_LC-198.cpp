// https://leetcode.com/problems/house-robber/description/?envType=daily-question&envId=2024-01-21

class Solution {
public:
    vector<int>dp;
    int f(vector<int>&nums, int i){
        if (i==nums.size()-1){
            return nums[i];
        }
        if (i==nums.size()-2){
            return max(nums[i], nums[i+1]);
        }
        if (dp[i]!=-1){
            return dp[i];
        }
        return dp[i] = max(nums[i] + f(nums, i+2), 0 + f(nums, i+1));
    }
    int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(405, -1);
        return f(nums, 0);
    }
};