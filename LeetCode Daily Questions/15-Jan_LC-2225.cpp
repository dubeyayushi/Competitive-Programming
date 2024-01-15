//https://leetcode.com/problems/find-players-with-zero-or-one-losses/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>ans;
        vector<int>ans1;
        vector<int>ans2;
        unordered_map<int ,int>loss;
        unordered_set<int>s;
        for (int i = 0; i<matches.size(); i++){
            loss[matches[i][1]]++;
            s.insert(matches[i][0]);
            s.insert(matches[i][1]);
        }

        for (int ele : s){
            if (loss.find(ele)==loss.end()){
                ans1.push_back(ele);
            }
        }
        sort(ans1.begin(), ans1.end());
        ans.push_back(ans1);
        for (auto ele : loss){
            if (ele.second==1){
                ans2.push_back(ele.first);
            }
        }
        sort(ans2.begin(), ans2.end());
        ans.push_back(ans2);
        return ans;
    }
};