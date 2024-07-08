// https://leetcode.com/problems/word-break/

class Solution {
public:
    unordered_map<string, bool>dp;
    unordered_set<string>wordSet;

    bool helper(string s){
        if (dp.find(s)!=dp.end()){
            return dp[s];
        }
        if (wordSet.find(s)!=wordSet.end()){
            return dp[s] = true;
        }
        for (int i = 1; i<s.length(); i++){
            string prefix = s.substr(0, i);
            if (wordSet.find(prefix)!=wordSet.end()){
                string suffix = s.substr(i);
                if (helper(suffix)){
                    return dp[s] = true;
                }
            }
        }
        return dp[s] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        dp.clear();
        for (string ele : wordDict){
            wordSet.insert(ele);
        }
        return helper(s);
    }
};