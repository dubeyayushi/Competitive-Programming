// https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxIdx = n-1;
        long long sum = 0;
        for (int i = 0; i<nums.size(); i++){
            sum += nums[i];
        }
        while(maxIdx>=2){
            sum -= nums[maxIdx];
            if (nums[maxIdx]<sum){
                return sum += nums[maxIdx];
            }
            else{
                maxIdx--;
            }
        }
        return -1;
    }
};