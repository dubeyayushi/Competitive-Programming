// https://www.geeksforgeeks.org/problems/rod-cutting0840/1

class Solution{
  public:
    vector<int>dp;
    int solve(int price[], int n){
        if (n==0) {
            return 0;
        }
        if (dp[n]!=-1) return dp[n];
        int maxValue = 0;
        for (int i = 1; i<=n; i++){
            maxValue = max(maxValue, price[i-1] + solve(price, n-i));
        }
        return dp[n] = maxValue;
        
    }
    int cutRod(int price[], int n) {
        //code here
        dp.clear();
        dp.resize(n+1, -1);
        return solve(price, n);
    }
};