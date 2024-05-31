// https://leetcode.com/problems/single-number-iii/description/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorAll = 0;
        for (int i = 0; i<nums.size(); i++){
            xorAll ^= nums[i];
        }
        // xorAll now contains a^b, where a and b are unique elements
        // find least bit = 1 for xorAll
        int i = 0;
        while(((xorAll >> i) & 1) == 0){
            i++;
        }
        int a = 0, b = 0;
        for (int num : nums){
            if (((num >> i) & 1) == 0){
                a ^= num;
            }
            else{
                b ^= num;
            }
        }
        return {a, b};
    }
};