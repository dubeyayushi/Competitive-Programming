// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            ans = min(ans, nums[mid]);
            if (low==high && high==mid){
                break;
            }
            if (nums[low]<nums[mid]){   // left part is sorted
                ans = min(ans, nums[low]);
                low = mid+1;
            }
            else{   // right part is sorted
                ans = min(ans, nums[mid+1]);
                high = mid-1;
            }
        }
        return ans;
    }
};

