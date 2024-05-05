// https://leetcode.com/problems/two-sum/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>mp;
        vector<int>ans(2, 0);
        for (int i = 0; i<nums.size(); i++){
            if (mp.find(target-nums[i])!=mp.end()){
                ans[0] = i;
                ans[1] = mp[target-nums[i]];
                return ans;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};