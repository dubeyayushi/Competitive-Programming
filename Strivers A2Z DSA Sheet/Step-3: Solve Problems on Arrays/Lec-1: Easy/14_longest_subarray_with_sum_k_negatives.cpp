// https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_5713505?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
    // Write your code here
    unordered_map<int, int>mp;
    int n = nums.size();
    int sum = 0;
    int maxLen = 0;
    for (int i= 0; i<n; i++){
        sum += nums[i];
        if (sum==k){
            maxLen = max(maxLen, i+1);
        }
        int rem = sum - k;
        if (mp.find(rem)!=mp.end()){
            maxLen = max(maxLen, i-mp[rem]);
        }
        if (mp.find(sum)==mp.end()){
            mp[sum] = i;
        }
    }
    return maxLen;
}