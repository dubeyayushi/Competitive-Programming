// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description/?envType=daily-question&envId=2024-07-20

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rows = rowSum.size();
        int cols = colSum.size();
        vector<vector<int>>result(rows, vector<int>(cols, 0));
        while(true){
            int rowMin = INT_MAX;
            int colMin = INT_MAX;
            int rowIdx = 0;
            int colIdx = 0;
            for (int i = 0; i<rows; i++){
                if (rowSum[i]<rowMin && rowSum[i]!=-1){
                    rowMin = rowSum[i];
                    rowIdx = i;
                }
            }
            for (int i = 0; i<cols; i++){
                if (colSum[i]<colMin && colSum[i]!=-1){
                    colMin = colSum[i];
                    colIdx = i;
                }
            }
            if (rowMin==INT_MAX && colMin==INT_MAX) break;
            result[rowIdx][colIdx] = min(rowMin, colMin);
            rowSum[rowIdx] = rowSum[rowIdx] - min(rowMin, colMin);
            colSum[colIdx] = colSum[colIdx] - min(rowMin, colMin);
            if (rowSum[rowIdx]==0 && colSum[colIdx]==0){
                rowSum[rowIdx] = -1;
                colSum[colIdx] = -1;
            }
            else if (rowSum[rowIdx] == 0) rowSum[rowIdx] = -1;
            else colSum[colIdx] = -1;
        }
        return result;
    }
};