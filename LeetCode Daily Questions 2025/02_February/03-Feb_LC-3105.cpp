// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/?envType=daily-question&envId=2025-02-03

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLen = 1;
        int increasingLen = 1;
        int decreasingLen = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                increasingLen++;
                decreasingLen = 1; // Reset decreasing length
            } else if (nums[i] < nums[i - 1]) {
                decreasingLen++;
                increasingLen = 1; // Reset increasing length
            } else {
                increasingLen = 1;
                decreasingLen = 1;
            }
            maxLen = max(maxLen, max(increasingLen, decreasingLen));
        }
        
        return maxLen;
    }
};
