// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    void helper(vector<vector<int>>&result, vector<int>ans, vector<int>& candidates, int target, int idx){
        if (target==0){
            result.push_back(ans);
            return;
        }
        if (idx == candidates.size() || target < 0) {
            return;
        }
        ans.push_back(candidates[idx]);
        helper(result, ans, candidates, target-candidates[idx], idx);
        ans.pop_back();
        helper(result, ans, candidates, target, idx+1);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>ans;
        helper(result, ans, candidates, target, 0);
        return result;
    }
};