// https://leetcode.com/problems/move-zeroes/description/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0; i<nums.size(); i++){
            for (int j = 0; j<nums.size()-i-1; j++){
                if (nums[j]==0){
                    swap(nums[j], nums[j+1]);
                }
            }
        }
    }
};