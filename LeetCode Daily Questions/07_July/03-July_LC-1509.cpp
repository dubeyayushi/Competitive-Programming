// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/

class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size()<=4) return 0;

        sort(nums.begin(), nums.end());

        int minDiff = INT_MAX;

        for (int left = 0, right = nums.size()-4; left<4; left++, right++){
            minDiff = min(minDiff, nums[right]-nums[left]);
        }
        return minDiff;
    }
};