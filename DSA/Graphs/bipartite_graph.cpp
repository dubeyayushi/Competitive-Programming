// leetcode 785 - is graph bipartite?

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool bfs(vector<vector<int>>& graph, int src, vector<int>&color, int n){
        queue<int>q;
        q.push(src);
        color[src] = 0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for (int neighbour : graph[curr]){
                if (color[neighbour]==-1){
                    color[neighbour] = !color[curr];
                    q.push(neighbour);
                }
                else if (color[curr]==color[neighbour]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();   // number of vertices
        vector<int>color(n, -1);
        // for handling disconnected graphs, we will go to every node and 
        // start a bfs from that node. if for any connected component, the graph
        // is not bipartite then the whole graph is not bipartite 
        for (int i = 0; i<n; i++){
            if (color[i] == -1){
                if (bfs(graph, i, color, n) == false) return false;
            }
        }
        return true;
    }
};

int main(){

    return 0;
}