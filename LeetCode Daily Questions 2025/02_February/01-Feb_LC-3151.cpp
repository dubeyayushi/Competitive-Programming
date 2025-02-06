// https://leetcode.com/problems/special-array-i/description/?envType=daily-question&envId=2025-02-01

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 0; i<nums.size()-1; i++){
            int a = nums[i];
            int b = nums[i+1];
            if ((a%2==0 && b%2!=0) || (a%2!=0 && b%2==0)){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};