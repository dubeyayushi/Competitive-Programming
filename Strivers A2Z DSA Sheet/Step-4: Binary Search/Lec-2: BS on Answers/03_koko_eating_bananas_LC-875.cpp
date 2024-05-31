// https://leetcode.com/problems/koko-eating-bananas/description/

class Solution {
public:
    bool check(int x, vector<int>& piles, int h){
        long long totalTime = 0;
        for (int i = 0; i<piles.size(); i++){
            if (piles[i]%x==0){
                totalTime += piles[i]/x;
            }
            else{
                totalTime += (piles[i]/x) + 1;
            }
        }
        return totalTime <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = 0;
        int maxPile = INT_MIN;
        for (int i = 0; i<piles.size(); i++){
            maxPile = max(maxPile, piles[i]);
        }
        // applying binary search on answers with range [1, maxPile]
        int start = 1;
        int end = maxPile;
        while(start<=end){
            int mid = start + (end-start)/2;
            if (check(mid, piles, h)){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return start;
    }
};