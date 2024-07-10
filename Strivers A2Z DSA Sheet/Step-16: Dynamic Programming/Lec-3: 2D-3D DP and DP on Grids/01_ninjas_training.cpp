// https://www.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training

class Solution {
public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Memoization table, initialized to 0
        vector<vector<int>> dp(n, vector<int>(3, 0));
        
        // Initialize the first day's points
        dp[0][0] = points[0][0];
        dp[0][1] = points[0][1];
        dp[0][2] = points[0][2];
        
        // Iterate over each day
        for (int day = 1; day < n; day++) {
            // Update the points for each activity on the current day
            dp[day][0] = points[day][0] + max(dp[day - 1][1], dp[day - 1][2]);
            dp[day][1] = points[day][1] + max(dp[day - 1][0], dp[day - 1][2]);
            dp[day][2] = points[day][2] + max(dp[day - 1][0], dp[day - 1][1]);
        }
        
        // The result is the maximum points achievable on the last day
        return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
    }
};
