// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/?envType=daily-question&envId=2024-02-23

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>v;
        int n = nums.size();
        int i = 0;
        while(i<n){
            int correctIdx = nums[i] - 1;
            if (correctIdx == i || nums[i] == nums[correctIdx]){
                i++;
            }
            else{
                swap(nums[correctIdx], nums[i]);
            }
        }
        for (int i = 0; i<n; i++){
            if (nums[i]!=i+1){
                v.push_back(nums[i]);
            }
        }
        return v;
    }
};

