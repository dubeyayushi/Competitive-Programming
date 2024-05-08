// https://leetcode.com/problems/relative-ranks/description/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>>pq;
        for (int i = 0; i<score.size(); i++){
            pq.push({score[i], i});
        }
        vector<string>ans(score.size(), "0");
        int i = 0;
        while(!pq.empty()){
            auto ele = pq.top();
            pq.pop();
            int idx = ele.second;
            if (i==0){
                ans[idx] = "Gold Medal";
            }
            else if (i==1){
                ans[idx] = "Silver Medal";
            }
            else if (i==2){
                ans[idx] = "Bronze Medal";
            }
            else{
                ans[idx] = to_string(i+1);
            }
            i++;
        }
        return ans;
    }
};