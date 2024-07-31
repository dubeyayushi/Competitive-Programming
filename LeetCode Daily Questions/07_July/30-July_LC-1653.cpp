// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/?envType=daily-question&envId=2024-07-30

class Solution {
public:
    int minimumDeletions(string s) {
        int ans = INT_MAX;
        int n = s.length();
        if (n==1) return 0;
        int prefSumB = 0;
        int suffSumA = 0;
        for (int i = 0; i<n; i++){
            if (s[i]=='a') suffSumA++;
        }
        for (int i = 0; i<n; i++){
            if (s[i]=='a'){
                suffSumA--;
            }
            ans = min(ans, prefSumB + suffSumA);
            if (s[i]=='b'){
                prefSumB++;
            }
        }
        return ans;
    }
};
