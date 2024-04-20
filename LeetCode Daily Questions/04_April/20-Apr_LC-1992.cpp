// https://leetcode.com/problems/find-all-groups-of-farmland/description/

class Solution {
public:
    int rows, cols;
    vector<vector<int>> grid;
    vector<vector<int>>dir = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(int r, int c, vector<vector<bool>>&visited, vector<int>&v){
        visited[r][c] = true;
        for (int d = 0; d<4; d++){
            int newRow = r + dir[d][0];
            int newCol = c + dir[d][1];
            if (newRow >= rows || newCol >= cols || newRow < 0 || newCol < 0){
                continue;
            }
            if (grid[newRow][newCol]==1 && visited[newRow][newCol]==false){
                v[2] = max(v[2], newRow);
                v[3] = max(v[3], newCol);
                dfs(newRow, newCol, visited, v);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        grid = land;
        rows = land.size();
        cols = land[0].size();
        vector<vector<int>>ans;
        vector<vector<bool>>visited(rows, vector<bool>(cols, false));
        for (int i = 0; i<rows; i++){
            for (int j = 0; j<cols; j++){
                if (land[i][j]==1 && visited[i][j]==false){
                    vector<int>v = {i, j, i, j};
                    dfs(i, j, visited, v);
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};