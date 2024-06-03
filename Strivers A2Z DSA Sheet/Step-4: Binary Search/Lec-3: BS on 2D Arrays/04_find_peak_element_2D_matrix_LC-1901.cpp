// https://leetcode.com/problems/find-a-peak-element-ii/description/

class Solution {
public:

    // Helper function to find the index of the maximum element in a column
    int findMaxInColumn(vector<vector<int>>& mat, int col) {
        int max_row = 0;
        for (int row = 0; row < mat.size(); ++row) {
            if (mat[row][col] > mat[max_row][col]) {
                max_row = row;
            }
        }
        return max_row;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int left = 0;
        int right = cols - 1;

        while (left <= right) {
            int mid_col = left + (right - left) / 2;
            int max_row = findMaxInColumn(mat, mid_col);

            bool left_is_smaller = (mid_col == 0 || mat[max_row][mid_col] > mat[max_row][mid_col - 1]);
            bool right_is_smaller = (mid_col == cols - 1 || mat[max_row][mid_col] > mat[max_row][mid_col + 1]);

            if (left_is_smaller && right_is_smaller) {
                return {max_row, mid_col};
            } else if (!left_is_smaller) {
                right = mid_col - 1;
            } else {
                left = mid_col + 1;
            }
        }
        return {};
    }
};
