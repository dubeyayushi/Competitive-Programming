// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int>mp;
        for (int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int ans = -1;
        for (auto ele : mp){
            if (ele.first>0 && ele.first>ans && mp.find(-ele.first)!=mp.end()){
                ans = ele.first;
            }
        }
        return ans;
    }
};