// https://leetcode.com/problems/sort-array-by-increasing-frequency/description/?envType=daily-question&envId=2024-07-23

class Solution {
public:
    
    vector<int> frequencySort(vector<int>& nums) {
        vector<int>result;
        unordered_map<int, int>mp;
        for (int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        sort(nums.begin(), nums.end(), [&mp](int a, int b){
            if (mp[a] != mp[b]){
                return mp[a] < mp[b];
            }
            return a > b;
        });
        return nums;
    }
};