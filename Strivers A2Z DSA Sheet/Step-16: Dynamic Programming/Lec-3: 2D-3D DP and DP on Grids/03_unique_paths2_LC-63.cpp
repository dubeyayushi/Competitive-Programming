// https://leetcode.com/problems/unique-paths-ii/description/

class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<vector<int>>& obstacleGrid, int row, int col){
        if (row<0 || col <0 || row>=obstacleGrid.size() || col>=obstacleGrid[0].size() || obstacleGrid[row][col]==1){
            return 0;
        }
        if (row==obstacleGrid.size()-1 && col==obstacleGrid[0].size()-1){
            return 1;
        }
        if (dp[row][col]!=-1) return dp[row][col];
        return dp[row][col] = solve(obstacleGrid, row+1, col) + solve(obstacleGrid, row, col+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        dp.clear();
        dp.resize(obstacleGrid.size()+1, vector<int>(obstacleGrid[0].size()+1, -1));
        return solve(obstacleGrid, 0, 0);
    }
};