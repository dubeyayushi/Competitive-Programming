// https://leetcode.com/problems/two-sum/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int, int>m;
        for (int i = 0; i<nums.size(); i++){
            int temp = target-nums[i];
            if (m.find(temp)==m.end()){
                m[nums[i]] = i;
            }
            else{
                ans.push_back(m[temp]);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};