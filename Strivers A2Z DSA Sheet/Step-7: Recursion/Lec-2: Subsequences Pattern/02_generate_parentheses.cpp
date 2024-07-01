// https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    void helper(vector<string>& result, string s, int n, int opening, int closing){
        if (opening == n && closing == n){
            result.push_back(s);
            return;
        }
        if (opening<n){
            helper(result, s + '(', n, opening+1, closing);
        }
        if (closing<opening){
            helper(result, s + ')', n, opening, closing+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        helper(result, "", n, 0, 0);
        return result;
    }
};