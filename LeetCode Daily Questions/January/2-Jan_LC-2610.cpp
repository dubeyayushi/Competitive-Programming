// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/?envType=daily-question&envId=2024-01-01

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
 
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>ans;
        unordered_map<int, int>mp;
        for (int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int n = 0;
        for (auto& ele : mp){
            n = max(n, ele.second);
        }
        for (int i = 0; i<n; i++){
            vector<int>v;
            for (auto& ele : mp){
                if (ele.second>0){
                    v.push_back(ele.first);
                    ele.second--;
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};

