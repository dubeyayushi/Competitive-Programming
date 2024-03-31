// https://leetcode.com/problems/find-the-duplicate-number/description/?envType=daily-question&envId=2024-02-23

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i<n){
            int correctIdx = nums[i]-1;
            if (i==correctIdx){
                i++;
            }
            else if (nums[i] != nums[correctIdx]){
                swap(nums[i], nums[correctIdx]);
            }
            else{
                return nums[i];
            }
        }
        return 1000;
    }
};

