// https://leetcode.com/problems/count-number-of-nice-subarrays/description/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        int odd = 0;
        int count = 0;
        while (j<n){
            if (nums[j]%2!=0){
                count= 0;
                odd++;
            }
            while(i<=j && odd == k){
                count++;
                if (nums[i++]%2 != 0){
                    odd--;
                }
            }
            ans += count;
            j++;
        }
        return ans;
    }
};