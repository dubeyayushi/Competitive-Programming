// https://leetcode.com/problems/maximum-total-importance-of-roads/

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, int>mp;  //store city, frequency
        long long ans = 0;

        for (int i = 0; i<roads.size(); i++){
            mp[roads[i][0]]++;
            mp[roads[i][1]]++;
        }

        priority_queue<pair<int, int>>pq;
        for (auto ele : mp){
            pq.push({ele.second, ele.first});
        }

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            mp[curr.second] = n;   //now mp stores city, value
            n--;
        }

        for (int i = 0; i<roads.size(); i++){
            ans += mp[roads[i][0]] + mp[roads[i][1]];
        }
        return ans;
    }
};