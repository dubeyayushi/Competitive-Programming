// https://leetcode.com/problems/set-mismatch/description/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>v;
        int n = nums.size();
        int i = 0;
        while(i<n){
            int correctIdx = nums[i]-1;
            if (correctIdx==i || nums[i]==nums[correctIdx]){
                i++;
            }
            else{
                swap(nums[i], nums[correctIdx]);
            }
        }
        for (int i = 0; i<n; i++){
            if (nums[i]!=i+1){
                v.push_back(nums[i]);
                v.push_back(i+1);
                break;
            }
        }
        return v;
    }
};