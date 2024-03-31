// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int>mp;
        for (int i = 0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for (auto ele : mp){
            pq.push({ele.second, ele.first});
        }
        while(k>0){
            pair<int, int>curr = pq.top();
            int freq = curr.first;
            if (freq<=k){
                k = k - freq;
                pq.pop();
                continue;
            }
            else{
                return pq.size();
            }
        }
        return pq.size();
    }
};