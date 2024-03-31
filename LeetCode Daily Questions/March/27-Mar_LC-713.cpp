// https://leetcode.com/problems/subarray-product-less-than-k/description/?envType=daily-question&envId=2024-02-23

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k<=1){
            return 0;
        }
        int product = 1;
        int count = 0;
        int i = 0, j = 0;
        int n = nums.size();
        while(j<n){
            product *= nums[j];
            while (product>=k){
                count += (j-i);
                product /= nums[i];
                i++;
            }
            j++;
        }
        while (i<n){
            count += (j-i);
            product /= nums[i];
            i++;
        }
        return count;
    }
};

