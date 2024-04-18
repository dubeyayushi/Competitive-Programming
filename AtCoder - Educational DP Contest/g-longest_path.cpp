#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
using namespace std;
 
vector<int> graph[100005];
int dp[100005];

int findLongestPath(int src){
    if (dp[src]!=-1) return dp[src];

    bool leaf = 1;
    int maxValue = 0;
    for (int child : graph[src]){
        leaf = 0;
        maxValue = max(maxValue, findLongestPath(child));
    }
    return dp[src] = leaf ? 0 : 1 + maxValue;
}

int main(){
    memset(dp, -1, sizeof(dp));
    int n, m;
    cin >> n >> m;
    while(m--){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    int result = INT_MIN;
    for (int i = 1; i<=n; i++){
        result = max(result, findLongestPath(i));
    }
    cout << result;
}