// https://leetcode.com/problems/convert-1d-array-into-2d-array/description/

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans;
        if (m*n != original.size()) return ans;
        int count = 0;
        for (int i = 0; i<m; i++){
            vector<int>v;
            for (int j = 0; j<n; j++){
                v.push_back(original[count++]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};