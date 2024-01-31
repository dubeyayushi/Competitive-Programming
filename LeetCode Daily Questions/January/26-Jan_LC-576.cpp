// https://leetcode.com/problems/out-of-boundary-paths/description/?envType=daily-question&envId=2024-01-26

#define mod 1000000007
class Solution {
public:
    int dp[52][52][60];
    int f(int m, int n, int maxMove, int i, int j, int moves){
        if (moves>maxMove){
            return INT_MAX;
        }
        if (i==m || j==n || i<0 || j<0){
            return 1;
        }
        if (dp[i][j][moves]!=-1){
            return dp[i][j][moves];
        }
        int a = f(m, n, maxMove, i+1, j, moves+1);
        int b = f(m, n, maxMove, i, j+1, moves+1);
        int c = f(m, n, maxMove, i-1, j, moves+1);
        int d = f(m, n, maxMove, i, j-1, moves+1);
        return dp[i][j][moves] = (((a==INT_MAX ? 0 : a) % mod + (b==INT_MAX ? 0 : b) % mod) % mod + ((c==INT_MAX ? 0 : c) % mod + (d==INT_MAX ? 0 : d) % mod) % mod) % mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return f(m, n, maxMove, startRow, startColumn, 0);
    }
};

