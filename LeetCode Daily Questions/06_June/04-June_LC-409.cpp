// https://leetcode.com/problems/longest-palindrome/description/

class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        unordered_map<char, int>mp;
        for (int i = 0; i<s.length(); i++){
            mp[s[i]]++;
        }
        int maxOddSum = 0;
        bool oddPresent = false;
        for (auto ele : mp){
            char ch = ele.first;
            int freq = ele.second;
            if (freq%2==0){
                ans += freq;
            }
            else{
                maxOddSum += (freq-1);
                oddPresent = true;
            }
        }
        if (oddPresent) ans += maxOddSum + 1;
        return ans;
    }
};