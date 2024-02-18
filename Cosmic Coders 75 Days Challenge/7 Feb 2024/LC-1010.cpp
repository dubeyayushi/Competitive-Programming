// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/description/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        vector<int>mp(60, 0);
        int ans = 0;
        for (int i = 0; i<n; i++){
            int curr = time[i]%60;
            if (curr==0){
                ans += mp[curr];
            }
            else{
                ans += mp[60-curr];
            }
            mp[curr]++;
        }
        return ans;
    }
};