// https://leetcode.com/problems/palindromic-substrings/description/

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>>dp(n, vector<bool>(n, false));
        int count = 0;
        // all individual characters are palindromes
        for (int i = 0; i<n; i++){
            dp[i][i] = true;
            count++;
        }
        //palindromes of length 2
        for (int i = 0; i<n-1; i++){
            if (s[i]==s[i+1]){
                dp[i][i+1] = true;
                count++;
            }
        }
        //palindromes of length greater than 2
        for (int i = 3; i<=n; i++){
            for (int j = 0; j<=n-i; j++){
                int k = j + i - 1;
                if (dp[j+1][k-1] && s[j] == s[k]){
                    dp[j][k] = true;
                    count++;
                }
            }
        }
        return count;
    }
};