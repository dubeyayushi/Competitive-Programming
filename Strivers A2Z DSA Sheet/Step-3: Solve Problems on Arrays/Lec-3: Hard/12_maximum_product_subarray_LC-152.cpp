// https://leetcode.com/problems/maximum-product-subarray/description/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre = 1;
        int suff = 1;
        int ans = INT_MIN;
        for (int i = 0; i<nums.size(); i++){
            if (pre==0) pre = 1;
            if (suff==0) suff = 1;
            pre = pre * nums[i];
            suff = suff * nums[nums.size()-i-1];
            ans = max(ans, max(pre, suff));
        }
        return ans;
    }
};