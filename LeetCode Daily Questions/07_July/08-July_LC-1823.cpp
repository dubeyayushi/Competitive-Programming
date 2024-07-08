// https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/?envType=daily-question&envId=2024-07-08

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        for (int i = 1; i<=n; i++){
            q.push(i);
        }
        while(q.size()!=1){
            int count = 1;
            while(count<k){
                q.push(q.front());
                q.pop();
                count++;
            }
            q.pop();
        }
        return q.front();
    }
};