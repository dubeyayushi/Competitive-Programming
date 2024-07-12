// https://leetcode.com/problems/target-sum/description/

class Solution {
public:
    unordered_map<string, int>dp;
    int solve(vector<int>& nums, int target, int idx){
        if (idx>=nums.size()){
            return target==0;
        }
        string key = to_string(idx) + "," + to_string(target);
        if (dp.find(key)!=dp.end()){
            return dp[key];
        }
        return dp[key] = (solve(nums, target+nums[idx], idx+1) + solve(nums, target-nums[idx], idx+1));
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0);
    }
};