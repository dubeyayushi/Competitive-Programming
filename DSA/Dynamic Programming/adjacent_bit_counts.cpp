#include<bits/stdc++.h>
#include<vector>
using namespace std;
 
int dp[105][105][2];
int result = 0;

int f(int n, int k, int last){
    if (n==0){
        return 0;
    }
    if (n==1){
        if (k==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    if (dp[n][k][last]!=-1){
        return dp[n][k][last];
    }
    if (last==1){
        result = f(n-1, k-1, 1) + f(n-1, k, 0);
    }
    else{
        result = f(n-1, k, 1) + f(n-1, k, 0);
    }
    return dp[n][k][last] = result;
}

int main(){
    memset(dp, -1, sizeof(dp));
    int p;
    cin >> p;
    for (int i = 1; i<=p; i++){
        int a, n, k;
        cin >> a >> n >> k;
        cout << i << " " << f(n, k, 0) + f(n, k, 1) << endl;
    }
}