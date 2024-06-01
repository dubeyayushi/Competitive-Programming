// https://leetcode.com/problems/split-array-largest-sum/description/

class Solution {
public: 
    bool check(int sum, vector<int>& nums, int k){
        int totalSum = 0;
        int subarrayCount = 1;
        for (int i = 0; i<nums.size(); i++){
            if (totalSum + nums[i] <= sum){
                totalSum += nums[i];
            }
            else{
                totalSum = nums[i];
                subarrayCount++;
            }
            if (subarrayCount>k) return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int maxele = INT_MIN;
        int sum = 0;
        for (int i = 0; i<nums.size(); i++){
            maxele = max(maxele, nums[i]);
            sum += nums[i];
        }
        int start = maxele;
        int end = sum;
        while(start<=end){
            int mid = start + (end-start)/2;
            if (check(mid, nums, k)){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return start;
    }
};