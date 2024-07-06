// https://leetcode.com/problems/pass-the-pillow/description/

class Solution {
public:
    int passThePillow(int n, int time) {
        if (n==time+1) return n;
        int round = time/(n-1);
        int steps = time%(n-1);
        if (round%2!=0){
            return n-steps;
        }
        return steps+1;
    }
};