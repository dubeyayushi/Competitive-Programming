// https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/0?category&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=max-sum-in-sub-arrays

class Solution{
    public:
        long long pairWithMaxSum(long long arr[], long long N)
    {
        // Your code goes here
        long long ans = 0;
        for (int i = 0; i<N-1; i++){
            long long val = arr[i] + arr[i+1];
            ans = max(val, ans);
        }
        return ans;
    }
};