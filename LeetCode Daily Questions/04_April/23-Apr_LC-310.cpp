// https://leetcode.com/problems/minimum-height-trees/?envType=daily-question&envId=2024-04-24

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n==1) return {0};
        vector<list<int>>graph(n, list<int>());
        vector<int> indegree(n, 0);
        for (auto edge : edges){
            int x = edge[0];
            int y = edge[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
            indegree[x]++;
            indegree[y]++;
        }
        queue<int>q;
        for (int i = 0; i<n; i++){
            if(indegree[i]==1) q.push(i);
        }
        int remainingNodes = n;
        while(remainingNodes > 2){
            int leavesCount = q.size();
            remainingNodes -= leavesCount;
            for (int i = 0; i<leavesCount; i++){
                int leaf = q.front();
                q.pop();
                for (int neighbour : graph[leaf]){
                    if (--indegree[neighbour] == 1){
                        q.push(neighbour);
                    }
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};