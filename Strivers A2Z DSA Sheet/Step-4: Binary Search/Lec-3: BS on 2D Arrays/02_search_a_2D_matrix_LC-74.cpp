// https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution {
public:
    bool helper(vector<vector<int>>& matrix, int target, int row){
        int start = 0;
        int end = matrix[0].size()-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if (matrix[row][mid]==target) return true;
            else if (matrix[row][mid]<target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool ans = false;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i<n; i++){
            bool rowAns = helper(matrix, target, i);
            ans = ans | rowAns;
        }
        return ans;
    }
};