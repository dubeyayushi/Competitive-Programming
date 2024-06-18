// https://leetcode.com/problems/most-profit-assigning-work/description/

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        sort(worker.begin(), worker.end());
        reverse(worker.begin(), worker.end());

        priority_queue<pair<int,int>>pq; // storing {profit, difficulty}

        for (int i = 0; i<profit.size(); i++){
            pq.push({profit[i], difficulty[i]});
        }

        int ans = 0;
        int i = 0;
        while(i<worker.size()){
            if (pq.empty()) break;
            auto curr = pq.top();
            if (worker[i]<curr.second){
                pq.pop();
            }
            else{
                ans += curr.first;
                i++;
            }
        }
        return ans;
    }
};