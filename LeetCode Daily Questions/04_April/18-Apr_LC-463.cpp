// https://leetcode.com/problems/island-perimeter/

class Solution {
public:
    vector<vector<int>>dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>>v;
    int rows, cols;
    int ans = 0;
    void dfs(int r, int c, vector<vector<bool>>& visited) {
        if (r >= rows || c >= cols || r < 0 || c < 0) return;
        if (visited[r][c] || v[r][c] == 0) return; // If already visited or water, return
        visited[r][c] = true;
        int numDir = 0;
        for (int d = 0; d < 4; d++) {
            int newRow = r + dir[d][0]; // Update row index
            int newCol = c + dir[d][1]; // Update column index
            if (newRow >= rows || newCol >= cols || newRow < 0 || newCol < 0 || v[newRow][newCol] == 0) {
                numDir++; // Increment count for water cells
                continue;
            }
            if (!visited[newRow][newCol]) dfs(newRow, newCol, visited);
        }
        ans += numDir; // Add the count for water cells to the perimeter
}

    int islandPerimeter(vector<vector<int>>& grid) {
        v = grid;
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<bool>>visited(rows, vector<bool>(cols, false));
        for (int i = 0; i<rows; i++){
            for (int j = 0; j<cols; j++){
                if (grid[i][j]==1){
                    dfs(i, j, visited);
                    return ans;
                }
            }
        }
        return ans;
    }  
};