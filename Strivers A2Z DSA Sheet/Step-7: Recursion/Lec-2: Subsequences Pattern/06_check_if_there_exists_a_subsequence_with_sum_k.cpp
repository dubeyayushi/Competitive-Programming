// https://www.naukri.com/code360/problems/subset-sum_630213?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

vector<vector<int>>dp;

bool helper(int idx, vector<int>&a, int n, int k){
    if (idx==n){
        return k==0;
    }
    if (dp[idx][k]!=-1){
        return dp[idx][k];
    }
    if (helper(idx+1, a, n, k)){
        return dp[idx][k] = true;
    }
    if (k>=a[idx] && helper(idx+1, a, n, k-a[idx])){
        return dp[idx][k] = true;
    }
    return dp[idx][k] = false;
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here
    dp.resize(n+1, vector<int>(k+1, -1));
    return helper(0, a, n, k);
}