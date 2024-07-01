// https://leetcode.com/problems/subsets/

class Solution {
public:
    void helper(vector<vector<int>>& result, vector<int>ans, vector<int>& nums, int idx){
        if (idx==nums.size()){
            result.push_back(ans);
            return;
        }
        helper(result, ans, nums, idx+1);
        ans.push_back(nums[idx]);
        helper(result, ans, nums, idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>ans;
        helper(result, ans, nums, 0);
        return result;
    }
};