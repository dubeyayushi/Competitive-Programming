// https://leetcode.com/problems/valid-anagram/description/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length()!=t.length()) return false;
        unordered_map<char, int>mp1;
        unordered_map<char, int>mp2;
        for (int i = 0; i<s.length(); i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        for (auto ele : mp1){
            if (mp2.find(ele.first)==mp2.end()) return false;
            else if (mp2[ele.first]!=mp1[ele.first]) return false;
        }
        return true;
    }
};