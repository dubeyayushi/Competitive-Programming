// https://leetcode.com/problems/number-of-ways-to-split-array/description/

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ans = 0;
        vector<long long>prefixSum(nums.size());
        vector<long long>suffixSum(nums.size());
        prefixSum[0] = nums[0];
        suffixSum[nums.size()-1] = nums[nums.size()-1];
        for (int i = 1; i<nums.size(); i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
            suffixSum[nums.size()-i-1] = suffixSum[nums.size()-i] + nums[nums.size()-i-1];
        }
        for (int i = 0; i<nums.size()-1; i++){
            if (prefixSum[i] >= suffixSum[i+1]) ans++;
        }
        return ans;
    }
};
