// https://leetcode.com/problems/relative-sort-array/description/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>v;
        unordered_map<int, int>mp;
        for (int i = 0; i<arr1.size(); i++){
            mp[arr1[i]]++;
        }
        for (int ele : arr2){
            auto p = mp.find(ele);
            int size = p->second;
            for (int i = 0; i<size; i++){
                v.push_back(p->first);
            }
            mp.erase(ele);
        }
        int l = mp.size();
        vector<int>temp;
        if (l){
            for (auto x : mp){
                for (int i = 0; i<x.second; i++){
                    temp.push_back(x.first);
                }
            }
        }
        sort(temp.begin(), temp.end());
        for (int i = 0; i<temp.size(); i++){
            v.push_back(temp[i]);
        }
        return v;
    }
};