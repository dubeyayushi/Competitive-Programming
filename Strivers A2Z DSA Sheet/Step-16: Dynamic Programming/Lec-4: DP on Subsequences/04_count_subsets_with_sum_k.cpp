// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=perfect-sum-problem

#define mod 1000000007
class Solution{
	public:
	vector<vector<int>>dp;
	int solve(int arr[], int n, int sum, int idx){
	    if (idx>=n){
	        return sum==0;
	    }
	    if (dp[idx][sum]!=-1) return dp[idx][sum];
	    int ans = 0;
	    ans += solve(arr, n, sum, idx+1);
	    ans %= mod;
	    if (arr[idx]<=sum){
	        ans += solve(arr, n, sum-arr[idx], idx+1);
	        ans %= mod;
	    }
	    return dp[idx][sum] = ans;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        dp.clear();
        dp.resize(n+1, vector<int>(sum+1, -1));
        return solve(arr, n, sum, 0);
	}
	  
};