// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/description/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorAll = nums[0];
        int ans = 0;
        for (int i = 1; i<nums.size(); i++){
            xorAll = xorAll ^ nums[i];
        }
        xorAll = xorAll ^ k;
        while(xorAll){
            if (xorAll & 1){
                ans++;
            }
            xorAll = xorAll >> 1;
        }
        return ans;
    }
};