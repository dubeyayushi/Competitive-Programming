// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minDay = INT_MAX;
        for (int i = 0; i<prices.size(); i++){
            minDay = min(minDay, prices[i]);
            ans = max(ans, prices[i] - minDay);
        }
        return ans;
    }
};