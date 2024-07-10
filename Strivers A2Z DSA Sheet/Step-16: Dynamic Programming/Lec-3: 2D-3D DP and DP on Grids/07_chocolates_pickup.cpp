// https://www.geeksforgeeks.org/problems/chocolates-pickup/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=chocolates-pickup

class Solution {
  public:
    int dp[70][70][70];
    int helper(int i, int j1, int j2, vector<vector<int>>&grid){
        if (i<0 || i>=grid.size() || j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size()){
            return INT_MIN;
        }
        if (i==grid.size()-1){
            if (j1==j2) return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }
        if (dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi = INT_MIN;
        for (int x = -1; x<=1; x++){
            for (int y = -1; y<=1; y++){
                int ans = INT_MIN;
                if (j1==j2) {
                    ans = grid[i][j1] + helper(i+1, j1+x, j2+y, grid);
                }
                else ans = grid[i][j1] + grid[i][j2] + helper(i+1, j1+x, j2+y, grid); 
                maxi = max(ans, maxi);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        int rows = grid.size();
        int cols = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, cols-1, grid);
    }
};