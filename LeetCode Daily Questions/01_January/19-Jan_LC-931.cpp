//https://leetcode.com/problems/minimum-falling-path-sum/description/?envType=daily-question&envId=2024-01-19

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int ans = INT_MAX;
        vector<vector<int>>dp(rows, vector<int>(cols, INT_MAX));
        for (int i = 0; i<cols; i++){
            dp[0][i] = matrix[0][i];
        }
        for (int i = 1; i<rows; i++){
            for (int j = 0; j<cols; j++){
                if (j-1<0 && j+1>=cols){
                    dp[i][j] = matrix[i][j] + dp[i-1][j];
                }
                else if (j-1<0){
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i-1][j+1]);
                }
                else if (j+1>=cols){
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
                }
                else{
                    dp[i][j] = matrix[i][j] + min({dp[i-1][j], dp[i-1][j+1], dp[i-1][j-1]});
                }
            }
        }
        for (int i = 0; i<cols; i++){
            ans = min(ans, dp[rows-1][i]);
        }
        return ans;
    }
};

