// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=knapsack-with-duplicate-items

class Solution{
public:
    vector<vector<int>>dp;
    int solve(int n, int w, int val[], int wt[], int idx){
        if (idx==n || w==0){
            return 0;    
        }
        if (dp[idx][w]!=-1) return dp[idx][w];
        int exclude = solve(n, w, val, wt, idx+1);
        int include = 0;
        if (wt[idx]<=w){
            include = val[idx] + solve(n, w-wt[idx], val, wt, idx);
        }
        return dp[idx][w] = max(include, exclude);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        dp.clear();
        dp.resize(N+1, vector<int>(W+1, -1));
        return solve(N, W, val, wt, 0);
    }
};