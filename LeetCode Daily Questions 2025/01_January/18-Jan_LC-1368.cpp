// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/?envType=daily-question&envId=2025-01-18

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int dy[4] = {1, -1, 0, 0};
        int dx[4] = {0, 0, 1, -1};

        int dist[n][m]; // distance of any element from source

       for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            dist[i][j] = 1e9;
        }
       }

        deque<pair<int, int>>dq;
        dq.push_back({0, 0});
        dist[0][0] = 0;

        while(!dq.empty()){
            auto curr = dq.front();
            dq.pop_front();
            int x = curr.first;
            int y = curr.second;

            int dir = grid[x][y];

            for (int i = 0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                int edgeWt = 1;
                if (i+1==dir) edgeWt = 0;

                if (nx < n && ny < m && nx >=0 && ny >=0){
                    // next cell lies in the grid
                    if (dist[nx][ny] > dist[x][y] + edgeWt){
                        dist[nx][ny] = dist[x][y] + edgeWt;
                        if (edgeWt==1){
                            dq.push_back({nx, ny});
                        }
                        else{
                            dq.push_front({nx, ny});
                        }
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};