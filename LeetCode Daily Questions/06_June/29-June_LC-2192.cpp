// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        vector<int>indegree(n, 0);
        vector<set<int>>ancestors(n);
        vector<vector<int>>result(n);

        for (auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int>q;
        for (int i = 0; i<n; i++){
            if (indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for (int neighbour : graph[node]){
                ancestors[neighbour].insert(node);
                for (int anc : ancestors[node]){
                    ancestors[neighbour].insert(anc);
                }
                if(--indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            result[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }

        return result;
    }
};