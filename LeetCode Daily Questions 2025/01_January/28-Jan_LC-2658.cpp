// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/?envType=daily-question&envId=2025-01-28

class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid){
        if (row>=grid.size() || col>=grid[0].size() || row<0 || col<0 || grid[row][col]==0) return 0;
        int dirs[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int ans = grid[row][col];
        grid[row][col] = 0;
        for (auto dir : dirs){
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            ans += dfs(newRow, newCol, grid);
        }
        return ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    vector<vector<int>> gridCopy = grid;
                    ans = max(ans, dfs(i, j, gridCopy));
                }
            }
        }
        return ans;
    }
};