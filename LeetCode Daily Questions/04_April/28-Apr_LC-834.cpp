// https://leetcode.com/problems/sum-of-distances-in-tree/description/

class Solution {
public:
    vector<list<int>> graph;
    vector<int> count; // count of nodes in subtree rooted at each node
    vector<int> ans;   // sum of distances from each node to all other nodes
    
    void dfs1(int node, int parent) {
        for (int neighbor : graph[node]) {
            if (neighbor != parent) {
                dfs1(neighbor, node);
                count[node] += count[neighbor];
                ans[node] += ans[neighbor] + count[neighbor];
            }
        }
        count[node]++;
    }
    
    void dfs2(int node, int parent, int n) {
        for (int neighbor : graph[node]) {
            if (neighbor != parent) {
                ans[neighbor] = ans[node] - count[neighbor] + (n - count[neighbor]);
                dfs2(neighbor, node, n);
            }
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph.clear();
        graph.resize(n, list<int>());
        count.resize(n, 0);
        ans.resize(n, 0);
        
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        dfs1(0, -1);
        dfs2(0, -1, n);
        
        return ans;
    }
};
