// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

class Solution{   
public:
    vector<vector<int>>dp;
    bool helper(vector<int>&arr, int idx, int sum){
        if (sum==0) return true;
        if (idx==arr.size()) return false;
        if (sum<0){
            return false;
        }
        if (dp[idx][sum]!=-1) return dp[idx][sum];
        bool a = helper(arr, idx+1, sum);
        bool b = helper(arr, idx+1, sum-arr[idx]);
        return dp[idx][sum] = a || b;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        dp.clear();
        dp.resize(arr.size()+1, vector<int>(sum+1, -1));
        return helper(arr, 0, sum);
    }
};