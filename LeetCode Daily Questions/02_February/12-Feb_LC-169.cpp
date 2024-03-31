// https://leetcode.com/problems/majority-element/description/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maj = nums[0];
        int count = 1;
        int i = 0;
        for (int i = 0; i<n-1; i++){
            if (nums[i] == nums[i+1]){
                count++;
                if (count > n/2){
                    return nums[i];
                }
            }
        }
        return maj;
    }
};