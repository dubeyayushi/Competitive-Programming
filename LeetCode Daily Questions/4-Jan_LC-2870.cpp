// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/?envType=daily-question&envId=2024-01-01

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
 
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int>mp;
        int ans = 0;
        for (int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for (auto ele : mp){
            int freq = ele.second;
            if (freq == 1){
                return -1;
            }
            ans += freq/3;
            if (freq%3){
                ans++;
            }
        }
        return ans;
    }
};