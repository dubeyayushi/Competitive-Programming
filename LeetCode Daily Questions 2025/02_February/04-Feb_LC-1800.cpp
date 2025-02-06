// https://leetcode.com/problems/maximum-ascending-subarray-sum/description/?envType=daily-question&envId=2025-02-04

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0];
        int sum = nums[0];
        for (int i = 1; i<nums.size(); i++){
            if (nums[i]>nums[i-1]){
                sum += nums[i];
            }
            else{
                sum = nums[i];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};