// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/?envType=daily-question&envId=2024-01-28

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();   //rows
        int n = matrix[0].size();  //columns

        //finding the prefix sum of every row and updating in the same matrix
        for (int i = 0; i<m; i++){
            for (int j = 1; j<n; j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
        int ans = 0;    //initialising ans variable to 0

        //traversing the matrix columns pair-wise
        for (int col1 = 0; col1<n; col1++){
            for (int col2 = col1; col2<n; col2++){

                //creating a map to store the number of occurences of each sum
                unordered_map<int, int>mp;
                //initialising the number of occurences of sum = 0 as 1
                mp[0] = 1;
                //creating sum variable
                int sum = 0;

                //traversing row-wise for the column pairs
                for (int row = 0; row<m; row++){
                    //finding the sum which is the difference of the current value and the value in the previous column of the matrix containing the prefix sum
                    sum += matrix[row][col2] - (col1>0 ? matrix[row][col1-1] : 0);
                    ans += mp[sum-target];
                    mp[sum]++;
                }
            }
        }
        return ans;
    }
};