// https://leetcode.com/problems/maximize-happiness-of-selected-children/description/

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int>pq;
        for (int i = 0; i<happiness.size(); i++){
            pq.push(happiness[i]);
        }
        int i = 0;
        long long ans = 0;
        while(!pq.empty() && k>0){
            int curr = pq.top();
            pq.pop();
            if (curr-i>=0) ans += (curr - i);
            i++;
            k--;
        }
        return ans;
    }
};