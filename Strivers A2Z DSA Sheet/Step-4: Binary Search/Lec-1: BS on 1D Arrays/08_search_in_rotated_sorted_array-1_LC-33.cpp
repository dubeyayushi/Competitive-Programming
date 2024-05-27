// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if (nums[mid]==target){
                return mid;
            }
            else if (nums[low]<=nums[mid]){ // left part is sorted
                if (nums[low]<=target && nums[mid]>target){    // target lies in left half, eliminate right half
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else{   // right part is sorted
                if (nums[high]>=target && nums[mid]<target){ // target lies in right half, eliminate left half
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};