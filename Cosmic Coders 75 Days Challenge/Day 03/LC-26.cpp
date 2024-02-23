// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int>s;
        s.insert(nums[0]);
        int k = 1;
        for (int i = 1; i<nums.size(); i++){
            if (s.find(nums[i])==s.end()){
                s.insert(nums[i]);
                nums[k] = nums[i];
                k++;
            }
        }
        return k;      
    }
};