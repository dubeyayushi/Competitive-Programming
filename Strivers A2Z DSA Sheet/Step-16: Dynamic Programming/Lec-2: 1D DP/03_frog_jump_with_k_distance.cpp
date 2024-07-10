// https://www.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost

class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        if (n==1) return 0;
        vector<int>dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i<n; i++){
            for (int j = 1; j<=k; j++){
                if (i-j>=0) dp[i] = min(dp[i], dp[i-j] + abs(height[i] - height[i-j]));
            }
        }
        return dp[n-1];
    }
};

