// https://leetcode.com/problems/redundant-connection/description/?envType=daily-question&envId=2025-01-29

class Solution {
public:
    bool isConnected(int src, int target, vector<bool>&visited, vector<vector<int>>&adjList){
        visited[src] = true;
        if (src==target){
            return true;
        }
        int isFound = false;
        for (int adj : adjList[src]){
            if (!visited[adj]){
                isFound = isFound || isConnected(adj, target, visited, adjList);
            }
        }
        return isFound;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>>adjList(n);

        for (auto edge : edges){
            vector<bool> visited(n, false);
            if (isConnected(edge[0]-1, edge[1]-1, visited, adjList)){
                return edge;
            }
            adjList[edge[0]-1].push_back(edge[1]-1);
            adjList[edge[1]-1].push_back(edge[0]-1);
        }
        return {};
    }
};