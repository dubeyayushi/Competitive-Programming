// https://www.interviewbit.com/problems/subarray-with-given-xor/

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int xr = 0;
    unordered_map<int, int>mp;
    mp[xr]++;
    int count = 0;
    for (int i = 0; i<n; i++){
        xr = xr ^ A[i];
        int x = xr ^ B;
        count += mp[x];
        mp[xr]++;
    }
    return count;
}
