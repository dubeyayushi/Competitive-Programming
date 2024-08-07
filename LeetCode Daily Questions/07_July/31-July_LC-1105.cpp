// https://leetcode.com/problems/filling-bookcase-shelves/description/?envType=daily-question&envId=2024-07-31

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int>dp(n+1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i<=n; i++){
            int totalWidth = 0;
            int maxHeight = 0;
            for (int j = i; j>0; j--){
                totalWidth += books[j-1][0];
                if (totalWidth > shelfWidth) break;

                maxHeight = max(maxHeight, books[j-1][1]);
                dp[i] = min(dp[i], dp[j-1] + maxHeight);
            }
        }
        return dp[n];
    }
};