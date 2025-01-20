// https://leetcode.com/problems/first-completely-painted-row-or-column/description/?envType=daily-question&envId=2025-01-20

class Solution {
public:
    
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = arr.size();
        int rows = mat.size();
        int cols = mat[0].size();
        vector<pair<int, int>>indices(n+1);
        unordered_map<int, int>rowMap;
        unordered_map<int, int>colMap;
        for (int i = 0; i<rows; i++){
            rowMap[i] = cols;
        }
        for (int i = 0; i<cols; i++){
            colMap[i] = rows;
        }
        for (int i = 0; i<rows; i++){
            for (int j = 0; j<cols; j++){
                int val = mat[i][j];
                indices[val] = {i, j};
            }
        }
        for (int i = 0; i<n; i++){
            int row = indices[arr[i]].first;
            int col = indices[arr[i]].second;
            if (mat[row][col]!=-1){
                mat[row][col] = -1;
                rowMap[row]--;
                colMap[col]--;
            } 
            if (rowMap[row]==0 || colMap[col]==0) {
                return i;
            }
        }
        return n;
    }
};  