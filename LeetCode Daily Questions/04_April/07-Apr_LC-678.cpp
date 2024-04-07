// https://leetcode.com/problems/valid-parenthesis-string/description/

class Solution {
public:
    string str;
    vector<vector<int>>dp;
    bool helper(int index, int openCount){
        if (index==str.length()){
            return (openCount==0);
        }
        if (dp[index][openCount]!=-1){
            return dp[index][openCount];
        }
        bool flag = false;
        //if *, explore all possibilities
        if (str[index]=='*'){
            flag |= helper(index+1, openCount+1);
            flag |= helper(index+1, openCount);
            if (openCount){
                flag |= helper(index+1, openCount-1);
            }
        }
        else {
            // for ( and )
            if (str[index]=='('){
                flag = helper(index+1, openCount+1);
            }
            else if (openCount){
                flag = helper(index+1, openCount-1);
            }
        }
        return dp[index][openCount] = flag;
    }
    bool checkValidString(string s) {
        str = s;
        dp.clear();
        dp.resize(s.size(), vector<int>(s.size(), -1));
        return (helper(0, 0));
    }
};