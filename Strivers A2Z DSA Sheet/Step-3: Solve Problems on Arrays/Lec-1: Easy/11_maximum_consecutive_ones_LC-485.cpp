// https://leetcode.com/problems/max-consecutive-ones/description/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int i = 0;
        int count = 0;
        while(i<nums.size()){
            if (nums[i]!=0){
                count++;
            }
            else{
                count = 0;
            }
            ans = max(ans, count);
            i++;
        }
        return ans;
    }
};