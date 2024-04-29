#include<iostream>
#include<cstring>
#include<vector>
#define ll long long int
using namespace std;
 
vector<ll>captains(10005, 0);
vector<ll>assistants(0005, 0);
ll dp[10005][5005];
int n;

ll f(int i, int x){
    if (dp[i][x]!=-1){
        return dp[i][x];
    }
    if (i==n){
        return 0;
    }
    if (x==0){
        return dp[i][x] = f(i+1, x+1) + assistants[i];
    }
    if (x==n-i){
        return dp[i][x] = f(i+1, x-1) + captains[i];
    }
    else{
        return dp[i][x] = min(f(i+1, x+1) + assistants[i], f(i+1, x-1) + captains[i]); 
    }
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> captains[i] >> assistants[i];
    }
    cout <<  assistants[0] + f(1, 1) << endl;
    return 0;
}