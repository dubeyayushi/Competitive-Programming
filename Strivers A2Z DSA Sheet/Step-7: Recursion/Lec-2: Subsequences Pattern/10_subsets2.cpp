// https://leetcode.com/problems/subsets-ii/

class Solution {
public:
    void helper(vector<vector<int>>&result, vector<int>ans, vector<int>&nums, int idx){
        result.push_back(ans);
        for (int i = idx; i<nums.size(); i++){
            if (i>idx && nums[i]==nums[i-1]){
                continue;
            }
            ans.push_back(nums[i]);
            helper(result, ans, nums, i+1);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>ans;
        sort(nums.begin(), nums.end());
        helper(result, ans, nums, 0);
        return result;
    }
};