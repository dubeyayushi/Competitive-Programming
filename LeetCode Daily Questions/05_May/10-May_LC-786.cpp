// https://leetcode.com/problems/k-th-smallest-prime-fraction/description/

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;
        for (int i = 0; i<arr.size(); i++){
            for (int j = i+1; j<arr.size(); j++){
                double val = (double)arr[i]/(double)arr[j];
                pq.push({val, {arr[i], arr[j]}});
            }
        }
        for (int i = 0; i<k-1; i++){
            pq.pop();
        }
        vector<int>ans(2);
        ans[0] = pq.top().second.first;
        ans[1] = pq.top().second.second;
        return ans;
    }
};