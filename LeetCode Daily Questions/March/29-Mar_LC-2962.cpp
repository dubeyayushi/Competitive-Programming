// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/?envType=daily-question&envId=2024-02-23

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long maxEle = nums[0];
        int n = nums.size();
        for (int i = 0; i<nums.size(); i++){
            maxEle = max<long long>(maxEle, nums[i]);
        }
        long long int left = 0, right = 0, ans = 0, count = 0;
        while(right < n){
            if (nums[right]==maxEle){
                count++;
            }
            while(count>=k){
                if (nums[left]==maxEle){
                    count--;
                }
                left++;
                ans += (n-right);
            }
            right++;
        }
        return ans;
    }
};

