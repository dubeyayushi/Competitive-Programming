// https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/

class Solution {
public:
    void helper(vector<int>&nums, int idx, int currXor, int& ans){
        if (idx==nums.size()){
            ans += currXor;
            return;
        }
        helper(nums, idx+1, currXor ^ nums[idx], ans);
        helper(nums, idx+1, currXor, ans);
    }
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        helper(nums, 0, 0, ans);
        return ans;
    }
};