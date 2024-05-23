// https://leetcode.com/problems/the-number-of-beautiful-subsets/description/

class Solution {
public:
    int helper(vector<int>&nums, int k, unordered_map<int, int>&mp, int i){
        if (i==nums.size()){
            return 1;
        }
        int totalCount = helper(nums, k, mp, i+1);
        if (!mp[nums[i]-k]){
            mp[nums[i]]++;
            totalCount += helper(nums, k, mp, i+1);
            mp[nums[i]]--;
        }
        return totalCount;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        sort(nums.begin(), nums.end());
        return helper(nums, k, mp, 0) - 1;
    }
};