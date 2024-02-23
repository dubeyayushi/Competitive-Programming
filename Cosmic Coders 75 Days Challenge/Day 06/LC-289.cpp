// https://leetcode.com/problems/game-of-life/description/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>arr = board;
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i<rows; i++){
            for (int j = 0; j<cols; j++){
                int neighbours = ((j+1<cols) ? arr[i][j+1] : 0) + ((i+1<rows) ? arr[i+1][j] : 0) + (((i+1<rows) && (j+1<cols)) ? arr[i+1][j+1] : 0) + ((j-1>=0) ? arr[i][j-1] : 0) + ((i-1>=0) ? arr[i-1][j] : 0) + ((i-1>=0 && j-1>=0) ? arr[i-1][j-1] : 0) + ((i-1>=0 && j+1<cols) ? arr[i-1][j+1] : 0) + ((i+1<rows && j-1>=0) ? arr[i+1][j-1] : 0);
                if (arr[i][j]==1){
                    if (neighbours<2){
                        board[i][j] = 0;
                    }
                    else if (neighbours>3){
                        board[i][j] = 0;
                    }
                }
                else{
                    if (neighbours==3){
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
};