// https://leetcode.com/problems/score-after-flipping-matrix/description/

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i<m; i++){
            if (grid[i][0] == 1){
                continue;
            }
            else{
                for (int j = 0; j<n; j++){
                    if (grid[i][j]==1){
                        grid[i][j] = 0;
                    }
                    else{
                        grid[i][j] = 1;
                    }
                }
            }
        }

        for (int j = 0; j<n; j++){
            int one = 0, zero = 0;
            for (int i = 0; i<m; i++){
                if (grid[i][j]==1){
                    one++;
                }
                else{
                    zero++;
                }
            }
            if (one<zero){
                for(int i = 0; i<m; i++){
                    if (grid[i][j] == 1){
                        grid[i][j] = 0;
                    }
                    else{
                        grid[i][j] = 1;
                    }
                }
            }
        }
        int sum = 0;;
        for (int i = 0; i<m; i++){
            int x = 1;
            for (int j = n-1; j>=0; j--){
                sum += grid[i][j]*x;
                x*=2;
            }
        }
        
        return sum;

    }
};