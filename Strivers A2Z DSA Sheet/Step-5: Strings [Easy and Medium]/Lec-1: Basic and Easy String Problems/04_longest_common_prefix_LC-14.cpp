// https://leetcode.com/problems/longest-common-prefix/description/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        sort(strs.begin(), strs.end());
        int i = 0;
        int j = 0;
        string word1 = strs[0];
        string word2 = strs[strs.size()-1];
        while(i<word1.length() && j<word2.length()){
            if (word1[i]==word2[j]){
                ans += word1[i];
                i++;
                j++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};