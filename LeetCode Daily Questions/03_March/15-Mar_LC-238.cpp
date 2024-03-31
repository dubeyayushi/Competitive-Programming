// https://leetcode.com/problems/product-of-array-except-self/description/?envType=daily-question&envId=2024-02-23

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n);
        vector<int>suffix(n);

        int p = nums[0];
        prefix[0] = 1;

        for (int i = 1; i<n; i++){
            prefix[i] = p;
            p *= nums[i];
        }
        //suffix product array in prefix only
        p = nums[n-1];
        for (int i = n-2; i>=0; i--){
            prefix[i] *= p;
            p *= nums[i];
        }
        return prefix;
    }
};