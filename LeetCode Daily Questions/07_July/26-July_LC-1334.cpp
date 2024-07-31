// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/?envType=daily-question&envId=2024-07-26

class Solution {
public:
    void dijkstra(int n, vector<vector<pair<int, int>>>& adjacencyList, vector<int>& shortestPathDistances, int source){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, source});
        fill(shortestPathDistances.begin(), shortestPathDistances.end(), INT_MAX);
        shortestPathDistances[source] = 0;
        while(!pq.empty()){
            auto [currentDistance, currentCity] = pq.top();
            pq.pop();
            if (currentDistance > shortestPathDistances[currentCity]){
                continue;
            }
            for (auto& [neighborCity, edgeWeight] : adjacencyList[currentCity]){
                if (shortestPathDistances[neighborCity] > currentDistance + edgeWeight){
                    shortestPathDistances[neighborCity] = currentDistance + edgeWeight;
                    pq.push({shortestPathDistances[neighborCity], neighborCity});
                }
            }
        }
    }
    int getCityWithFewestReachable(int n, vector<vector<int>>&shortestPathMatrix, int distanceThreshold){
        int cityWithFewestReachable = -1;
        int fewestReachableCount = n;
        for (int i = 0; i<n; i++){
            int reachableCount = 0;
            for (int j = 0; j<n; j++){
                if (i==j){
                    continue;
                }
                if (shortestPathMatrix[i][j] <= distanceThreshold){
                    reachableCount++;
                }
            }
            if (reachableCount <= fewestReachableCount){
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adjacencyList(n);
        vector<vector<int>>shortestPathMatrix(n, vector<int>(n, INT_MAX));
        for (int i = 0; i<n; i++){
            shortestPathMatrix[i][i] = 0;
        }
        for (auto& edge : edges){
            int start = edge[0];
            int end = edge[1];
            int weight = edge[2];
            adjacencyList[start].push_back({end, weight});
            adjacencyList[end].push_back({start, weight});
        }
        for (int i = 0; i<n; i++){
            dijkstra(n, adjacencyList, shortestPathMatrix[i], i);
        }
        return getCityWithFewestReachable(n, shortestPathMatrix, distanceThreshold);
    }
};

