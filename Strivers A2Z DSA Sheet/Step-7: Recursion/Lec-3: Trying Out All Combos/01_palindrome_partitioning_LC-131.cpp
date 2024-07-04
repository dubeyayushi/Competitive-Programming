// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    bool is_palindrome(string s, int start, int end){
        while(start<end){
            if (s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void helper(vector<vector<string>>&result, string s, vector<string>path, int idx){
        if (idx==s.length()){
            result.push_back(path);
            return;
        }
        for (int i = idx; i<s.length(); i++){
            if (is_palindrome(s, idx, i)){
                path.push_back(s.substr(idx, i-idx+1));
                helper(result, s, path, i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>path;
        helper(result, s, path, 0);
        return result;
    }
};