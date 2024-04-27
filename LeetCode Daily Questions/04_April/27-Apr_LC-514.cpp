// https://leetcode.com/problems/freedom-trail/description/

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        
        // Create a dp array to store the minimum steps required to spell each character
        vector<vector<int>> dp(m + 1, vector<int>(n, 0));
        
        // Iterate over each character in the key from right to left
        for (int i = m - 1; i >= 0; --i) {
            // Iterate over each character in the ring
            for (int j = 0; j < n; ++j) {
                // Initialize the minimum steps required to infinity
                dp[i][j] = INT_MAX;
                // Iterate over each character in the ring
                for (int k = 0; k < n; ++k) {
                    // If the character in the ring matches the character in the key
                    if (ring[k] == key[i]) {
                        // Calculate the steps required to reach this character
                        int steps = abs(j - k);
                        // Calculate the minimum steps required to spell the remaining characters
                        int minSteps = min(steps, n - steps) + dp[i + 1][k];
                        // Update the minimum steps if necessary
                        dp[i][j] = min(dp[i][j], minSteps);
                    }
                }
            }
        }
        
        // Return the minimum steps required to spell the first character of the key
        return dp[0][0] + m;
    }
};
