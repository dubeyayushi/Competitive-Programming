// https://leetcode.com/problems/find-pivot-index/description/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int rightSum= 0, leftSum = 0;
        for (int i = 0; i<n; i++){
            rightSum += nums[i];
        }
        for (int i = 0; i<n; i++){
            rightSum -= nums[i];
            if (leftSum==rightSum){
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};