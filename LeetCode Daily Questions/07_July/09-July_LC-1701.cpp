// https://leetcode.com/problems/average-waiting-time/description/

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double currTime = customers[0][0];
        double waitingTime = 0;
        for (int i = 0; i<customers.size(); i++){
            if (currTime>=customers[i][0]) currTime += customers[i][1];
            else currTime = customers[i][0] + customers[i][1];
            waitingTime += currTime - (double)customers[i][0];
        }
        return waitingTime/(double)customers.size();
    }
};