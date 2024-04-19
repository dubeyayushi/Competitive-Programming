// https://leetcode.com/problems/number-of-islands/description/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i<grid.size(); i++){
            for (int j = 0; j<grid[0].size(); j++){
                if (grid[i][j]=='0'){
                    continue;
                }
                //else new connected component found
                ans++;
                grid[i][j] = '0';

                //start bfs
                queue<pair<int, int>>q;
                q.push({i, j});
                while(!q.empty()){
                    auto curr = q.front(); // get one node from queue
                    q.pop();
                    int currRow = curr.first;
                    int currCol = curr.second;
                    if (currRow-1>=0 && grid[currRow-1][currCol]=='1'){
                        q.push({currRow-1, currCol});
                        grid[currRow-1][currCol]='0';
                    }
                    if (currCol-1>=0 && grid[currRow][currCol-1]=='1'){
                        q.push({currRow, currCol-1});
                        grid[currRow][currCol-1]='0';
                    }
                    if (currRow+1<grid.size() && grid[currRow+1][currCol]=='1'){
                        q.push({currRow+1, currCol});
                        grid[currRow+1][currCol]='0';
                    }
                    if (currCol+1<grid[0].size() && grid[currRow][currCol+1]=='1'){
                        q.push({currRow, currCol+1});
                        grid[currRow][currCol+1]='0';
                    }
                }
            }
        }
        return ans;
    }
};