// https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution {
public:

    int expand(string s, int left, int right){
        while(left>=0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }

        return right - left - 1;
    }

    string longestPalindrome(string s) {
        if (s.empty()){
            return "";
        }
        int start = 0;
        int end = 0;

        for (int i = 0; i<s.length(); i++){
            int odd = expand(s, i, i);
            int even = expand(s, i, i+1);
            int maxLen = max(odd, even);

            if (maxLen > end-start){
                start = i - (maxLen - 1)/2;
                end = i + maxLen/2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};