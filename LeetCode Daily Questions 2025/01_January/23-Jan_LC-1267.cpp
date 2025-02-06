// https://leetcode.com/problems/count-servers-that-communicate/description/?envType=daily-question&envId=2025-01-23

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<int>rowSum(m, 0);
        vector<int>colSum(n, 0);

        for (int row = 0; row<m; row++){
            for (int col = 0; col<n; col++){
                if (grid[row][col]==1){
                    rowSum[row]++;
                }
            }
        }
        for (int col = 0; col<n; col++){
            for (int row = 0; row<m; row++){
                if (grid[row][col]==1){
                    colSum[col]++;
                }
            }
        }
        for (int i = 0; i<m; i++){
            for (int j = 0; j<n; j++){
                if (grid[i][j]==1 && (rowSum[i]>1 || colSum[j]>1)){
                    ans++;
                }
            }
        }
        return ans;
    }
};