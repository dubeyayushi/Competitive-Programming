// https://leetcode.com/problems/sort-the-jumbled-numbers/description/?envType=daily-question&envId=2024-07-24

class Solution {
public:
    void solve(int val, map<int, vector<int>>&mp, vector<int>& mapping){
        int x = val;
        int temp = 0;
        int mul = 1;
        if (val==0){
            temp = mapping[val];
            mp[temp].push_back(val);
            return;
        }
        while(val){
            int digit = val%10;
            val = val/10;
            int mapVal = mapping[digit];
            temp = mapVal*mul + temp;
            mul *= 10;
        }
        mp[temp].push_back(x);
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<int, vector<int>>mp;
        for (int i = 0; i<nums.size(); i++){
            solve(nums[i], mp, mapping);
        }
        vector<int>ans;
        for (auto it : mp){
            for (int i = 0; i<it.second.size(); i++){
                ans.push_back(it.second[i]);
            }
        }
        return ans;
    }
};
