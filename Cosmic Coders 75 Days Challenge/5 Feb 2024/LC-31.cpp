// https://leetcode.com/problems/next-permutation/description/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot_idx = -1;
        for (int i = nums.size()-2; i>=0; i--){
            if (nums[i]<nums[i+1]){
                pivot_idx = i;
                break;
            }
        }

        if (pivot_idx == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        reverse(nums.begin() + pivot_idx + 1, nums.end());

        int j = -1;
        for (int i = pivot_idx+1; i<nums.size(); i++){
            if (nums[i]>nums[pivot_idx]){
                j = i;
                break;
            }
        }

        int temp = nums[pivot_idx];
        nums[pivot_idx] = nums[j];
        nums[j] = temp;
    }
};