// https://www.naukri.com/code360/problems/count-frequency-in-a-range_8365446?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

vector<int> countFrequency(int n, int x, vector<int> &nums){
    // Write your code here.
    vector<int>ans(n, 0);
    for (int i = 0; i<n; i++){
        ans[nums[i]-1]++;
    }
    return ans;
}