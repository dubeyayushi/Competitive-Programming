// https://leetcode.com/problems/pascals-triangle/description/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>v;
        for (int i = 0; i<numRows; i++){
            vector<int>row(i+1);
            for (int j = 0; j<=i; j++){
                if (j==0 || j==i){
                    row[j] = 1;
                }
                else{
                    row[j] = v[i-1][j-1] + v[i-1][j];
                }
            }
            v.push_back(row);
        }
        return v;
    }
};