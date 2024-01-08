//https://atcoder.jp/contests/dp/tasks/dp_a

#include<iostream>
#include<vector>
using namespace std;

vector<int>dp;
vector<int>heights;

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
    
    if (i + 1 < heights.size()) {
        result = min(result, f(i + 1) + abs(heights[i] - heights[i + 1]));
    }

    if (i + 2 < heights.size()) {
        result = min(result, f(i + 2) + abs(heights[i] - heights[i + 2]));
    }
    
    return dp[i] = result;
}

int main(){
    dp.clear();
    dp.resize(100005, -1);

    int n;
    cin >> n;
    
    heights.clear();
    heights.resize(n); 

    for (int i = 0; i<n; i++){
        cin >> heights[i];
    }
    cout << f(0) << endl;
    return 0;
}