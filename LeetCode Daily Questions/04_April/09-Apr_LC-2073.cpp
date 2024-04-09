// https://leetcode.com/problems/time-needed-to-buy-tickets/description/?envType=daily-question&envId=2024-04-09

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;
        int i = 0;
        while(tickets[k]!=0){
            if (tickets[i]==0){
                i++;
            }
            else{
                tickets[i]--;
                ans++;
                i++;
            }
            if (i==tickets.size()){
                i = 0;
            }
        }
        return ans;
    }
};