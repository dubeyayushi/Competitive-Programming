#include<iostream>
#include<vector>
#include<climits>
using namespace std;
 
vector<int>values;
vector<int>dp;

int f(int x){
    if (x==0){
        return 0;
    }
    if (dp[x]!=-2){
        return dp[x];
    }
    int result = INT_MAX;
    for (int i = 0; i<values.size(); i++){
        if (x-values[i]<0) continue;
        result = min(result, f(x-values[i]));
    }
    if (result==INT_MAX) return dp[x] = INT_MAX;
    return dp[x] = result + 1;
}

int main(){
    int n, x;
    cin >> n >> x;
    for (int i = 0; i<n; i++){
        int num;
        cin >> num;
        values.push_back(num);
    }
    dp.clear();
    dp.resize(1000005, -2);
    int ans = f(x);
    if (ans==INT_MAX){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }
    return 0;
}