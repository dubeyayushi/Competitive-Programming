// https://leetcode.com/problems/water-bottles/description/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int remBottles = numBottles;
        while(remBottles>=numExchange){
            ans += remBottles / numExchange;
            remBottles = (remBottles / numExchange) + (remBottles % numExchange);
        }
        return ans;
    }
};