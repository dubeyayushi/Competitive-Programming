// https://leetcode.com/problems/n-queens/

class Solution {
public:
    vector<vector<string>>result;
    vector<vector<string>>grid;

    bool canPlaceQueen(int row, int col, int n){
        for (int i = row-1; i>=0; i--){
            if (grid[i][col]=="Q"){
                return false;
            }
        }
        for (int i = row-1, j = col-1; i>=0 && j>=0; i--, j--){
            if (grid[i][j]=="Q"){
                return false;
            }
        }
        for (int i = row-1, j = col+1; i>=0 && j<n; i--, j++){
            if (grid[i][j]=="Q"){
                return false;
            }
        }
        return true;
    }

    void helper(int row, int n){
        if (row==n){
            vector<string>temp;
            for (int i = 0; i<n; i++){
                string s = "";
                for (int j = 0; j<n; j++){
                    s += grid[i][j];
                }
                temp.push_back(s);
            }
            result.push_back(temp);
        }
        for (int col = 0; col<n; col++){
            if (canPlaceQueen(row, col, n)){
                grid[row][col] = "Q";
                helper(row+1, n);
                grid[row][col] = ".";
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        grid.clear();
        result.clear();
        grid.resize(n, vector<string>(n, "."));
        helper(0, n);
        return result;
    }
};

