// https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i = 0, j = 1;
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int>mp;
        while(j<n){
            nums[j] += nums[i];
            i++;
            j++;
        }
        for (int i = 0; i<n; i++){
            if (nums[i]==k){
                ans++;
            }
            int x = nums[i]-k;
            if (mp.find(x)!=mp.end()){
                ans += mp[x];
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};