// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/?envType=daily-question&envId=2025-02-02

class Solution {
public:
    bool check(vector<int>& nums) {
        int pivot = -1;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                pivot = i;
                break;
            }
        }
        if (pivot == -1) return true; // If the array is already sorted, it's valid
        
        // Check if the array is sorted from pivot to end and from start to pivot - 1
        for (int i = pivot; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) return false;
        }
        for (int i = 0; i < pivot - 1; i++) {
            if (nums[i] > nums[i + 1]) return false;
        }
        
        // Check if it's a valid rotation by comparing first and last elements
        return (nums[n - 1] <= nums[0]);
    }
};
