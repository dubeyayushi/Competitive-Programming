// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i<nums.size(); i=i+3){
            vector<int>v;
            if (nums[i+1]-nums[i]<=k && nums[i+2]-nums[i+1]<=k && nums[i+2]-nums[i]<=k){
                v.push_back(nums[i]);
                v.push_back(nums[i+1]);
                v.push_back(nums[i+2]);
                ans.push_back(v);
            }
            else{
                return {};
            }
        }
        return ans;
    }
};