// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

class Solution {
public:
    bool check(int days, vector<int>& bloomDay, int m, int k){
        int count = 0;
        int numBouquets = 0;
        for (int i = 0; i<bloomDay.size(); i++){
            if (bloomDay[i] <= days){
                count ++;
            }
            else{
                numBouquets += (count/k);
                count = 0;
            }
        }
        numBouquets += (count/k);
        return numBouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans = -1;
        long long n = bloomDay.size();
        long long val = m * 1ll * k * 1ll;
        if (val>n) return -1;
        int maxDay = INT_MIN;
        int minDay = INT_MAX;
        for (int i = 0; i<n; i++){
            maxDay = max(maxDay, bloomDay[i]);
            minDay = min(minDay, bloomDay[i]);
        }
        int start = minDay;
        int end = maxDay;
        while(start<=end){
            int mid = start + (end-start)/2;
            if (check(mid, bloomDay, m, k)){
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