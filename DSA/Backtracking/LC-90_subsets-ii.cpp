// https://leetcode.com/problems/subsets-ii/description/

class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& ans, int start, vector<int>subset){
        ans.push_back(subset);
        for (int i = start; i<nums.size(); i++){
            if (i>start && nums[i]==nums[i-1]){
                continue;
            }
            subset.push_back(nums[i]);
            helper(nums, ans, i+1, subset);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>subset;
        sort(nums.begin(), nums.end());
        helper(nums, ans, 0, subset);
        return ans;
    }
};