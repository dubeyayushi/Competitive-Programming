// https://atcoder.jp/contests/dp/tasks/dp_d

#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
#define ll long long int
using namespace std;

int n;
int w;
vector<int>values;
vector<int>weights;
ll dp[105][100005];
 
ll f(int idx, int w){
    if (idx==n){
        return 0;
    }
    if (dp[idx][w]!=-1){
        return dp[idx][w];
    }
    ll ans = INT_MIN;
    ans = max(ans, f(idx+1, w));
    if (weights[idx]<=w){
        ans = max(ans, values[idx] + f(idx+1, w-weights[idx]));
    }
    return dp[idx][w] = ans;
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
    cout << f(0, w) << endl;
    return 0;
}