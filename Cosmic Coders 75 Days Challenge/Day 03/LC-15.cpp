// https://leetcode.com/problems/3sum/description/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        set<vector<int>>s;
        for (int i = 0; i<nums.size(); i++){
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                if (nums[i] + nums[j] + nums[k] == 0){
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if (nums[i] + nums[j] + nums[k] < 0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        for (auto v : s){
            ans.push_back(v);
        }
        return ans;
    }
};