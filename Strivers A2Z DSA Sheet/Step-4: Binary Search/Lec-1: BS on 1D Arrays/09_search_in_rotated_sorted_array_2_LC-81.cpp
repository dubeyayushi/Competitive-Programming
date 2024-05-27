// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if (nums[mid]==target){
                return true;
            }
            else if (nums[mid]==nums[low] && nums[low]==nums[high]){
                while(low<=high && nums[mid]==nums[low] && nums[low]==nums[high]){
                    low++;
                    high--;
                }
            }
            else if (nums[low]<=nums[mid]){ // left half is sorted
                if (nums[low]<=target && nums[mid]>target){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else{
                if (nums[high]>=target && nums[mid]<target){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return false;
    }
};