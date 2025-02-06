// https://leetcode.com/problems/find-eventual-safe-states/description/?envType=daily-question&envId=2025-01-24

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);
        for (int i = 0; i<n; i++){
            for (int j = graph[i].size()-1; j>=0; j--){
                int v = graph[i][j];
                adj[v].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for (int i = n-1; i>=0; i--){
            if (indegree[i]==0) q.push(i);
        }
        vector<bool> safe(n, 0);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            safe[x] = 1;
            for (int y : adj[x]){
                if (--indegree[y] == 0){
                    q.push(y);
                }
            }
        }
        vector<int>ans;
        for (int i = 0; i<n; i++){
            if (safe[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};