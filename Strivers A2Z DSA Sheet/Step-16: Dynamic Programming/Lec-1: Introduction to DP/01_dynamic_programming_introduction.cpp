// https://www.geeksforgeeks.org/problems/introduction-to-dp/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=introduction-to-dp

#define mod 1000000007

class Solution {
  public:
  vector<long long>dpTopDown;
    long long int helperTopDown(int n){
        if (n==0) return 0;
        if (n==1 || n==2) return 1;
        if (dpTopDown[n]!=-1) return dpTopDown[n];
        return dpTopDown[n] = (helperTopDown(n-1) + helperTopDown(n-2))%mod;
    }
    long long int topDown(int n) {
        // code here
        dpTopDown.clear();
        dpTopDown.resize(n+1, -1);
        return helperTopDown(n);
    }
    long long int bottomUp(int n) {
        // code here
        vector<long long>dpBottomUp(n+1, -1);
        dpBottomUp[0] = 0;
        dpBottomUp[1] = 1;
        dpBottomUp[2] = 1;
        if (n==0 || n==1 || n==2){
            return dpBottomUp[n];
        }
        for (int i = 3; i<=n; i++){
            dpBottomUp[i] = (dpBottomUp[i-1] + dpBottomUp[i-2])%mod;
        }
        return dpBottomUp[n];
    }
};