// https://leetcode.com/problems/house-robber-ii/description/

class Solution {
public:
    vector<int>dp;
    int solve(vector<int>&nums, int idx, int end){
        if (idx==end){
            return dp[idx] = nums[end];
        }
        if (idx>end){
            return dp[idx] = 0;
        }
        if (dp[idx]!=-1){
            return dp[idx];
        }
        return dp[idx] = max(nums[idx] + solve(nums, idx+2, end), 0 + solve(nums, idx+1, end));
    }
    int rob(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        dp.clear();
        dp.resize(nums.size()+1, -1);
        int first = solve(nums, 0, nums.size()-2);
        fill(dp.begin(), dp.end(), -1);
        int last = solve(nums, 1, nums.size()-1);
        return max(first, last);
    }
};