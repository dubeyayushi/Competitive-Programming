// https://leetcode.com/problems/word-search/description/

class Solution {
public:
    bool helper(vector<vector<char>>& board, string word, int row, int col, int idx){
        if (idx==word.length()){
            return true;
        }
        if (row==board.size() || col==board[0].size() || row<0 || col<0 || word[idx]!=board[row][col]){
            return false;
        }
        char ch = board[row][col];
        board[row][col] = '#';
        bool a = helper(board, word, row+1, col, idx+1);
        bool b = helper(board, word, row-1, col, idx+1);
        bool c = helper(board, word, row, col+1, idx+1);
        bool d = helper(board, word, row, col-1, idx+1);
        board[row][col] = ch;
        return a || b || c || d;
    }


    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i<rows; i++){
            for (int j = 0; j<cols; j++){
                if (helper(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};