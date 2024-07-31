// https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/?envType=daily-question&envId=2024-07-19

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>result;
        for (int row = 0; row<matrix.size(); row++){
            int minRow = INT_MAX;
            int minCol = INT_MAX;
            int minVal = INT_MAX;
            for (int i = 0; i<matrix[0].size(); i++){
                if (matrix[row][i]<minVal){
                    minRow = row;
                    minCol = i;
                    minVal = matrix[row][i];
                }
            }
            int maxVal = INT_MIN;
            for (int j = 0; j<matrix.size(); j++){
                if (matrix[j][minCol]>maxVal){
                    maxVal = matrix[j][minCol];
                }
            }
            if (minVal == maxVal){
                result.push_back(minVal);
            }
        }
        return result;
    }
};

