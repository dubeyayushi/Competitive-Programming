//https://atcoder.jp/contests/dp/tasks/dp_a

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int>dp;
vector<int>heights;
int k;

int f(int i){
    if (i>=heights.size()){
        return INT_MAX;
    }
    if (i==heights.size()-1){
        return 0;
    }
    if (dp[i]!=-1){
        return dp[i];
    }
    int result = INT_MAX;
    for (int j = 1; j<=k; j++){
        if (i+j>=heights.size()){
            break;
        }
        result = min(result, f(i+j) + abs(heights[i]-heights[i+j]));
    }    
    return dp[i] = result;
}

int main(){
    dp.clear();
    dp.resize(100005, -1);

    int n;
    cin >> n >> k;
    
    heights.clear();
    heights.resize(n); 

    for (int i = 0; i<n; i++){
        cin >> heights[i];
    }
    cout << f(0) << endl;
    return 0;
}