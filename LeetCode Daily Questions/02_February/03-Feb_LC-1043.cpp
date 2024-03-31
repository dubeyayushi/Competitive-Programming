// https://leetcode.com/problems/partition-array-for-maximum-sum/description/?envType=daily-question&envId=2024-02-03

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(k+1, 0);
        for (int i = n-1; i>=0; i--){
            int currMax = 0;
            int end = min(n, i+k);
            for (int j = i; j<end; j++){
                currMax = max(currMax, arr[j]);
                dp[i%(k+1)] = max(dp[i%(k+1)], dp[(j+1)%(k+1)] + currMax * (j-i+1));
            }
        }
        return dp[0];
    }
};