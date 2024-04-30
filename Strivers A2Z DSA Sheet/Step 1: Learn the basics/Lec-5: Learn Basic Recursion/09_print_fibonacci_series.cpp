// https://www.naukri.com/code360/problems/print-fibonacci-series_7421617?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

int dp[50];
int fibonacci(int i){
    if (i==0) return 0;
    if (i==1) return 1;
    if (dp[i]!=-1) return dp[i];
    return dp[i] = fibonacci(i-1) + fibonacci(i-2);
}

vector<int> generateFibonacciNumbers(int n) {
    // Write your code here.
    vector<int>ans(n);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i<n; i++){
        ans[i] = fibonacci(i);
    }
    return ans;
}