// https://leetcode.com/problems/palindrome-partitioning/description/

class Solution {
public:
    vector<vector<string>>result;
    bool is_palindrome(string str, int i, int j){
        while(i<j){
            if (str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void backtrack(string s, int start, vector<string>path){
        if (start == s.length()){
            result.push_back(path);
            return;
        }
        for (int end = start+1; end<=s.length(); end++){
            if (is_palindrome(s, start, end-1)){
                path.push_back(s.substr(start, end-start));
                backtrack(s, end, path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>path;
        backtrack(s, 0, path);
        return result;
    }
};