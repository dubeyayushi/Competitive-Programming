// https://leetcode.com/problems/find-if-path-exists-in-graph/description/

class Solution {
public:
    int find(vector<int>& parent, int x){
        return parent[x] = (parent[x]==x ? x : find(parent, parent[x]));
    }

    void Union(vector<int>& parent, vector<int>& rank, int x, int y){
        x = find(parent, x);
        y = find(parent, y);

        if (x==y) return;

        if (rank[x]>=rank[y]){
            parent[y] = x;
            rank[x]++;
        }
        else{
            parent[x] = y;
            rank[y]++;
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>parent(n+1);
        vector<int>rank(n+1, 0);

        for (int i = 0; i<n; i++){
            parent[i] = i;
        }

        for (auto edge : edges){
            Union(parent, rank, edge[0], edge[1]);
        }
        int parSource = find(parent, source);
        int parDest = find(parent, destination);

        return (parSource==parDest);
    }
};