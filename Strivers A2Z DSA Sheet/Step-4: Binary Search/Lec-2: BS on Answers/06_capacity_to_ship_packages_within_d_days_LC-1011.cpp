// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

class Solution {
public:
    bool check(int capacity, vector<int>& weights, int days){
        int totalDays = 1;
        int sum = 0;
        for (int i = 0; i<weights.size(); i++){
            if (sum + weights[i] > capacity){
                totalDays++;
                sum = weights[i];
                if (totalDays>days) return false;
            }
            else{
                sum += weights[i];
            }
        }
        return totalDays <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int ans = -1;
        int sum = 0;
        int maxwt = 0;
        for (int i = 0; i<weights.size(); i++){
            maxwt = max(maxwt, weights[i]);
            sum += weights[i];
        }
        int start = maxwt;
        int end = sum;
        while(start<=end){
            int mid = start + (end-start)/2;
            if (check(mid, weights, days)){
                end = mid-1;
                ans = mid;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};