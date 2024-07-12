// https://leetcode.com/problems/partition-equal-subset-sum/description/

class Solution {
public:
    vector<vector<int>>dp;
    bool solve(vector<int>&nums, int sum, int idx){
        if (sum==0) return true;
        if (idx>=nums.size()) return false;
        if (sum<0) return false;    
        if (dp[idx][sum]!=-1) return dp[idx][sum];

        if (nums[idx]>sum) return dp[idx][sum] = solve(nums, sum, idx+1);
        else return dp[idx][sum] = solve(nums, sum-nums[idx], idx+1) || solve(nums, sum, idx+1);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i<nums.size(); i++){
            sum += nums[i];
        }
        if (sum%2!=0) return false;
        dp.clear();
        dp.resize(nums.size()+1, vector<int>(sum+1, -1));
        return solve(nums, sum/2, 0);
    }
};

