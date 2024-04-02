// https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length()!=t.length()) return false;
        unordered_map<char, int>mp1;
        unordered_map<char, int>mp2;
        set<int>s1;
        set<int>s2;
        for (int i = 0; i<s.length(); i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        for (auto ele : mp1){
            s1.insert(ele.second);
        }
        for (auto ele : mp2){
            s2.insert(ele.second);
        }
        if (s1==s2) return true;
        return false;
    }
};