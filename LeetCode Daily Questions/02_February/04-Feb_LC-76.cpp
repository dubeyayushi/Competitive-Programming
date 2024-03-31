// https://leetcode.com/problems/minimum-window-substring/description/

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()){
            return "";
        }
        unordered_map<char, int>mp;
        for (int i = 0; i<t.length(); i++){
            mp[t[i]]++;
        }
        int count = t.length();
        int start = 0;
        int end = 0;
        int minLen = INT_MAX;
        int startIdx = 0;

        while(end < s.length()){
            if (mp[s[end++]]-- > 0){
                count--;
            }
            while(count==0){
                if (end-start < minLen){
                    startIdx = start;
                    minLen = end - start;
                }
                if (mp[s[start++]]++ == 0){
                    count++;
                }
            }
        }
        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};