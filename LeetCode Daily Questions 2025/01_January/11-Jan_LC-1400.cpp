// https://leetcode.com/problems/construct-k-palindrome-strings/description/

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length()<k) return false;
        unordered_map<char, int>mp;
        for (int i = 0; i<s.length(); i++){
            mp[s[i]]++;
        }
        int odd = 0;
        for (auto ele : mp){
            if (ele.second%2!=0) odd++;
        }
        if (odd>k) return false;
        return true;
    }
};