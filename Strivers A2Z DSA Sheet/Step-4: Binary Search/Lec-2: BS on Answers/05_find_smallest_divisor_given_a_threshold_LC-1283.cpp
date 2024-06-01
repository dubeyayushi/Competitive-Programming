// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

class Solution {
public:
    bool check(int x, vector<int>& nums, int threshold){
        int sum = 0;
        for (int i = 0; i<nums.size(); i++){
            if (nums[i]%x==0){
                sum += (nums[i]/x);
            }
            else{
                sum += (nums[i]/x) + 1;
            }
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans = 1;
        int maxele = INT_MIN;
        for (int i = 0; i<nums.size(); i++){
            maxele = max(maxele, nums[i]);
        }
        int start = 1;
        int end = maxele;
        while(start<=end){
            int mid = start + (end-start)/2;
            if (check(mid, nums, threshold)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};