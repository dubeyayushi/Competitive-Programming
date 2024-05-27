// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/

class Solution {
public:
    int specialArray(vector<int>& nums) {
        for (int x = 0; x<=nums.size(); x++){
            int count = 0;
            for (int i = 0; i<nums.size(); i++){
                if (nums[i]>=x){
                    count++;
                }
            }
            if (count==x) return x;
        }
        return -1;
    }
};