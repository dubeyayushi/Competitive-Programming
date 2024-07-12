// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=partitions-with-given-difference

#define mod 1000000007
class Solution {
  public:
  vector<vector<int>>dp;
    int solve(int n, int d, vector<int>&arr, int totalSum, int idx, int currSum){
        if (idx==n){
            if (abs(totalSum - currSum - currSum) == d && currSum >= abs(totalSum - currSum)){
                return 1;
            }
            else return 0;
        }
        if (dp[idx][currSum]!=-1) return dp[idx][currSum];
        return dp[idx][currSum] = (solve(n, d, arr, totalSum, idx+1, currSum) + solve(n, d, arr, totalSum, idx+1, currSum + arr[idx]))%mod;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int totalSum = 0;
        for (int num : arr){
            totalSum += num;
        }
        dp.clear();
        dp.resize(n+1, vector<int>(totalSum+1, -1));
        solve(n, d, arr, totalSum, 0, 0);
    }
};