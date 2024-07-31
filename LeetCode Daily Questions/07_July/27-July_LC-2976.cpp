// https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/?envType=daily-question&envId=2024-07-27

class Solution {
public:
    vector<long long>dijkstra(int startChar, vector<vector<pair<int, int>>>adjacencyList){
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>pq;
        pq.push({0, startChar});
        vector<long long>minCosts(26, -1);
        while(!pq.empty()){
            auto [currentCost, currentChar] = pq.top();
            pq.pop();
            if (minCosts[currentChar] != -1 && minCosts[currentChar] < currentCost){
                continue;
            }
            for (auto [targetChar, conversionCost] : adjacencyList[currentChar]){
                long long newTotalCost = currentCost + conversionCost;
                if (minCosts[targetChar] == -1 || newTotalCost < minCosts[targetChar]){
                    minCosts[targetChar] = newTotalCost;
                    pq.push({newTotalCost, targetChar});
                }
            }
        }
        return minCosts;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int, int>>> adjacencyList(26);
        for (int i = 0; i<original.size(); i++){
            adjacencyList[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }
        vector<vector<long long>> minConversionCosts(26, vector<long long>(26));
        for (int i = 0; i<26; i++){
            minConversionCosts[i] = dijkstra(i, adjacencyList);
        }
        long long ans = 0;
        for (int i = 0; i<source.length(); i++){
            if (source[i]!=target[i]){
                long long charConversionCost = minConversionCosts[source[i]-'a'][target[i]-'a'];
                if (charConversionCost == -1){
                    return -1;
                }
                ans += charConversionCost;
            }
        }
        return ans;
    }
};