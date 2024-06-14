// https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/?envType=daily-question&envId=2024-06-14

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 1; i<nums.size(); i++){
            if (nums[i] <= nums[i-1]){
                ans += abs(nums[i] - nums[i-1]) + 1;
                nums[i] += abs(nums[i] - nums[i-1]) + 1;
            }
        }
        return ans;
    }
};