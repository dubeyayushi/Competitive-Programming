// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2, -1);
        int start = 0;
        int end = nums.size()-1;
        // searching for first occurrence
        while(start<=end){
            int mid = start + (end-start)/2;
            if (nums[mid]==target){
                if (mid==0){
                    ans[0] = mid;
                    break;
                }
                else if (nums[mid-1]==target){
                    end = mid-1;
                }
                else{
                    ans[0] = mid;
                    break;
                }
            }
            else if (nums[mid]<target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        // searching for second occurrence
        start = 0;
        end = nums.size()-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if (nums[mid]==target){
                if (mid==nums.size()-1){
                    ans[1] = mid;
                    break;
                }
                else if (nums[mid+1]==target){
                    start = mid+1;
                }
                else{
                    ans[1] = mid;
                    break;
                }
            }
            else if (nums[mid]<target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
};