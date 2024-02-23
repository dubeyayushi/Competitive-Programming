// https://leetcode.com/problems/word-search/description/

class Solution {
public:
    vector<vector<char>>arr;
    int rows;
    int cols;
    string str;

    bool f(int i, int j, int k){
        if (k==str.length()){   //if we have matched all characters in the word, return true
            return true;
        }
        if (i==rows || i<0 || j==cols || j<0 || arr[i][j]!=str[k]){
            return false;   // if current cell is out of bounds or does not match the current characters in word, return false
        }
        char ch = arr[i][j];    //store the current character before exploring neighbours
        arr[i][j] = '#';    //mark the current cell as visited

        // explore neighbours in all four directions
        bool a = f(i+1, j, k+1);
        bool b = f(i-1, j, k+1);
        bool c = f(i, j+1, k+1);
        bool d = f(i, j-1, k+1);

        arr[i][j] = ch; //restore the original character

        return a || b || c || d;    //return true if any of the recursive calls return true

    }

    bool exist(vector<vector<char>>& board, string word) {
        arr = board;
        str = word;
        rows = arr.size();
        cols = arr[0].size();
        
        //iterate over each cell in the board
        for (int i = 0; i<rows; i++){
            for (int j = 0; j<cols; j++){
                //check if word can be formed starting from current cell
                if (f(i, j, 0)) return true;
            }
        }
        return false;
    }
};