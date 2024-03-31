// https://leetcode.com/problems/cherry-pickup-ii/description/?envType=daily-question&envId=2024-02-11

class Solution {
public:
    int dy[3] = {0, -1, 1};
    int rows, cols;
    int dp[75][75][75];
    vector<vector<int>> arr;
    int f(int i, int j, int y){
        if (i==rows){
            return 0;
        }
        if (j<0 || y<0 || j>=cols || y>=cols){
            return INT_MIN;
        }
        if (dp[i][j][y]!=-1){
            return dp[i][j][y];
        }
        int ans = 0;

        for (int k = 0; k<3; k++){
            for (int r = 0; r<3; r++){
                ans = max(ans, f(i+1, j + dy[k], y + dy[r]));
            }
        }
        ans = ans + ((j==y) ? arr[i][j] : arr[i][j] + arr[i][y]);
        return dp[i][j][y] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        arr = grid;
        rows = grid.size();
        cols = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return f(0, 0, cols-1);
    }
};