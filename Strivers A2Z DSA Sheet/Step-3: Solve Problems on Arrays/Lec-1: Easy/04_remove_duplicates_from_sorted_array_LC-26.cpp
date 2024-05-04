// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ele = nums[0];
        int idx = 1;
        int ans = 1;
        for (int i = 1; i<nums.size(); i++){
            if (nums[i]==ele) continue;
            else{
                ele = nums[i];
                nums[idx] = ele;
                idx++;
                ans++;
            }
        }
        return ans;
    }
};