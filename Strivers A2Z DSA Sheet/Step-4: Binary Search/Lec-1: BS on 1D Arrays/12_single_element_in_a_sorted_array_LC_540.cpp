// https://leetcode.com/problems/single-element-in-a-sorted-array/description/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        if (nums[0]!=nums[1]) return nums[0];
        if (nums[nums.size()-1]!=nums[nums.size()-2]) return nums[nums.size()-1]; 
        int low = 1;
        int high = nums.size()-2;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if (nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            //if we are in left half, then duplicates in order even, odd
            if ((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2==1 && nums[mid]==nums[mid-1])){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return 0;
    }
};