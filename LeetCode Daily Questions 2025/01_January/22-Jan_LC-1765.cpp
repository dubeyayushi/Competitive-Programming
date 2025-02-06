// https://leetcode.com/problems/map-of-highest-peak/description/?envType=daily-question&envId=2025-01-22

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>>height(m, vector<int>(n, -1));
        queue<pair<int, int>>q;

        for (int i = 0; i<m; i++){
            for (int j = 0; j<n; j++){
                if (isWater[i][j]){
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for (auto dir : dirs){
                int newRow = curr.first + dir[0];
                int newCol = curr.second + dir[1];
                if (newRow >=0 && newCol >= 0 && newRow < m && newCol < n && height[newRow][newCol]==-1){
                    height[newRow][newCol] = height[curr.first][curr.second] + 1;
                    q.push({newRow, newCol});
                }
            }
        }
        return height;
    }
};