// https://leetcode.com/problems/hand-of-straights/description/

class Solution {
public:
    bool helper(int idx, vector<int>& hand, int groupSize){
        int n = hand.size();
        int next = hand[idx]+1;
        hand[idx] = -1;
        int count = 1;
        idx += 1;
        while(idx<n && count<groupSize){
            if (hand[idx] == next){
                next = hand[idx] + 1;
                hand[idx] = -1;
                count++;
            }
            idx++;
        }
        return count == groupSize;
    }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n%groupSize != 0) return false;
        sort(hand.begin(), hand.end());
        for (int i = 0; i<hand.size(); i++){
            if (hand[i] >= 0){
                if (!helper(i, hand, groupSize)) return false;
            }
        }
        return true;
    }
};