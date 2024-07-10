// https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<vector<int>>& grid, int row, int col){
        if (row<0 || col<0 || row>=grid.size() || col>=grid[0].size()){
            return INT_MAX;
        }
        if (row==grid.size()-1 && col==grid[0].size()-1){
            return grid[row][col];
        }
        if (dp[row][col]!=-1) return dp[row][col];
        int a = solve(grid, row+1, col);
        int b = solve(grid, row, col+1);
        if (min(a,b)==INT_MAX){
            return INT_MAX;
        }
        return dp[row][col] = grid[row][col] + min(a, b);
    }
    int minPathSum(vector<vector<int>>& grid) {
        dp.clear();
        dp.resize(grid.size()+1, vector<int>(grid[0].size()+1, -1));
        return solve(grid, 0, 0);
    }
};