#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
using namespace std;
 
#define ll long long int

int n, w;
int dp[105][100005];
vector<int>weights;
vector<int>values;

ll f(int idx, int tval){
    if (tval==0){
        return 0;
    }
    if (idx==weights.size()){
        return INT_MAX;
    }
    if (dp[idx][tval] != -1){
        return dp[idx][tval];
    }
    ll ans = INT_MAX;
    ans = min(ans, f(idx+1, tval));
    if (values[idx]<=tval){
        ans = min(ans, weights[idx] + f(idx+1, tval-values[idx]));
    }
    return dp[idx][tval] = ans;
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> n >> w;
    for (int i = 0; i<n; i++){
        int w, v;
        cin >> w >> v;
        weights.push_back(w);
        values.push_back(v);
    }
    int ans = -1;
    for (int i = 0; i<=n*1000; i++){
        if (f(0, i) <= w){
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}