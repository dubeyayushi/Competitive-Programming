// https://leetcode.com/problems/isomorphic-strings/description/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> indexS(200, 0); 
        vector<int> indexT(200, 0);

        if (s.length()!=t.length()) return false;

        int len = s.length();

        for (int i = 0; i<len; i++){
            if (indexS[s[i]] != indexT[t[i]]){
                return false;
            }
            indexS[s[i]] = i+1;
            indexT[t[i]] = i+1;
        }
        return true;
    }
};