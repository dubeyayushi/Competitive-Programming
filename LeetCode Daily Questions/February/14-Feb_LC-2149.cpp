// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/?envType=daily-question&envId=2024-02-14

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>positives;
        vector<int>negatives;
        for (int i = 0; i<nums.size(); i++){
            if (nums[i]>0){
                positives.push_back(nums[i]);
            }
            else{
                negatives.push_back(nums[i]);
            }
        }
        int i = 0;
        int j = 0;
        while(i<nums.size()){
            nums[i] = positives[j];
            nums[i+1] = negatives[j++];
            i+=2;
        }
        return nums;
    }
};