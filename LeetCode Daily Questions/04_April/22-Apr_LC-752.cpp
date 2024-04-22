// https://leetcode.com/problems/open-the-lock/description/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>s;
        for (int i = 0; i<deadends.size(); i++){
            s.insert(deadends[i]);
        }
        if (s.count("0000")) return -1;

        queue<pair<string, int>>q;
        q.push({"0000", 0});
        unordered_set<string>visited;
        visited.insert("0000");

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            string currentComb = curr.first;
            int moves = curr.second;
            if (currentComb == target){
                return moves;
            }
            for (int i = 0; i<4; i++){
                for (int j : {-1, 1}){
                    int newDigit = (currentComb[i] - '0' + j + 10) % 10;
                    string newComb = currentComb;
                    newComb[i] = '0' + newDigit;

                    if (visited.count(newComb)==0 && s.count(newComb)==0){
                        visited.insert(newComb);
                        q.push({newComb, moves+1});
                    }
                }

            }
        }
        return -1;
    }
};