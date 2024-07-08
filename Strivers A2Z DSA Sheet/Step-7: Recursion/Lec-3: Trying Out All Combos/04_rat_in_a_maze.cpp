// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution{
    public:
    void helper(vector<vector<int>> &m, int n, vector<string>&result, string path, int row, int col){
        if (row>=m.size() || col>=m.size() || row<0 || col<0 || m[row][col]==0 || m[row][col]==-1){
            return;
        }
        if (row==m.size()-1 && col==m.size()-1){
            result.push_back(path);
            return;
        }
        int val = m[row][col];
        m[row][col] = -1;
        helper(m, n, result, path+"U", row-1, col);
        helper(m, n, result, path+"D", row+1, col);
        helper(m, n, result, path+"R", row, col+1);
        helper(m, n, result, path+"L", row, col-1);
        m[row][col] = val;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>result;
        helper(m, n, result, "", 0, 0);
        return result;
    }
};