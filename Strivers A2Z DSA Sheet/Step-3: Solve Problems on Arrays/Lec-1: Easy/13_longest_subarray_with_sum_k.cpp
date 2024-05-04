// https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int l = 0;
    int r = 0;
    int n = a.size();
    long long sum = a[0];
    int ans = 0;

    while(r<n){
        while (l<=r && sum>k){
            sum -= a[l];
            l++;
        }
        if (sum==k){
            ans = max(ans, r-l+1);
        }
        r++;
        if (r<n) sum += a[r];
    }
    return ans;
}