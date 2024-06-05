// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/

class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for (int i = 0; i<s.length(); i++){
            unordered_map<char, int>mp;
            for (int j = i; j<s.length(); j++){
                mp[s[j]]++;
                int maxFreq = 0, minFreq = INT_MAX;
                for (auto ele : mp){
                    maxFreq = max(maxFreq, ele.second);
                    minFreq = min(minFreq, ele.second);
                }
                ans = ans + (maxFreq - minFreq);
            }
        }
        return ans;
    }
};