// https://leetcode.com/problems/grid-game/?envType=daily-question&envId=2025-01-21

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long top = 0;
        for (int i = 0; i<grid[0].size(); i++){
            top += grid[0][i];
        }
        long long bottom = 0;
        long long res = LLONG_MAX;
        for (int i = 0; i<grid[0].size(); i++){
            top -= grid[0][i];
            res = min(res, max(top, bottom));
            bottom += grid[1][i];
        }
        return res;
    }
};