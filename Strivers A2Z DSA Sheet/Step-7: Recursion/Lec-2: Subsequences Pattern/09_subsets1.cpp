// https://www.geeksforgeeks.org/problems/subset-sums2234/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=subset-sums

class Solution {
public:
    void helper(vector<vector<int>>&result, vector<int>ans, vector<int>& candidates, int target, int idx){
        if (target<0){
            return;
        }
        if (target==0){
            result.push_back(ans);
            return;
        }
        for (int i = idx; i < candidates.size(); ++i) {
            // Skip duplicates
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            ans.push_back(candidates[i]);
            helper(result, ans, candidates, target - candidates[i], i + 1);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ans;
        sort(candidates.begin(), candidates.end());
        helper(result, ans, candidates, target, 0);
        return result;
    }
};