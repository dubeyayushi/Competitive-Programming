// https://leetcode.com/problems/combination-sum-iii/

class Solution {
public: 
    void helper(vector<vector<int>>&result, vector<int>ans, int k, int n, int start){
        if (n<0) return;
        if (k==0){
            if (n==0) result.push_back(ans);
            return;
        }
        for (int i = start; i<=9; i++){
            ans.push_back(i);
            helper(result, ans, k-1, n-i, i+1);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>result;
        vector<int>ans;
        helper(result, ans, k, n, 1);
        return result;
    }
};