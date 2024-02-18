// https://leetcode.com/problems/3sum-closest/description/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        int diff = INT_MAX;
        int i = 0;
        for (int i = 0; i<n; i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                int temp = abs(sum-target);
                if (diff>temp){
                    diff = temp;
                    ans = sum;
                }
                if (sum>target){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return ans;
    }
};