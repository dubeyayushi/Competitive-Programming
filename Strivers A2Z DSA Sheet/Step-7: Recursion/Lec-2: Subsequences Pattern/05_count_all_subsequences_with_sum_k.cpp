// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=perfect-sum-problem

#define mod 1000000007

class Solution {
public:
    int N;
    vector<vector<int>> dp;
    int helper(int idx, int sum, int arr[]){
        if (idx>=N){
            return sum == 0;
        }
        if (dp[idx][sum]!=-1){
            return dp[idx][sum];
        }
        int ans = 0;
        ans += helper(idx+1, sum, arr);
        ans %= mod;
        if (arr[idx] <= sum){
            ans += helper(idx+1, sum - arr[idx], arr);
            ans %= mod;
        }
        return dp[idx][sum] = ans;
    }
    int perfectSum(int arr[], int n, int sum) {
        N = n;
        dp.resize(n+1, vector<int> (sum+2, -1));
        return helper(0, sum, arr);
    }
};
