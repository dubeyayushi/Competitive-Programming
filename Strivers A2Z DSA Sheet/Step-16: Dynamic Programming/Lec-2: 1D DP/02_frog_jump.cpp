// https://www.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump

class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        if (n==1) return 0;
        vector<int>dp(n, 0);
        dp[0] = 0;
        dp[1] = abs(height[1]-height[0]);
        for (int i = 2; i<n; i++){
            dp[i] = min(dp[i-1] + abs(height[i] - height[i-1]), dp[i-2] + abs(height[i] - height[i-2]));
        }
        return dp[n-1];
        
    }
};

