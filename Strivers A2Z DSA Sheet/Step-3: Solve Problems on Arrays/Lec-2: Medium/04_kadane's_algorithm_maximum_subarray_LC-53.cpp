// https://leetcode.com/problems/maximum-subarray/description/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0;
        int sum = 0;
        int maxele = INT_MIN;
        for (int i = 0; i<nums.size(); i++){
            sum += nums[i];
            maxele = max(maxele, nums[i]);
            ans = max(sum, ans);
            if (sum<0) sum = 0;
        }
        if (maxele<0) return maxele;
        return ans;
    }
};