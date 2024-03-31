// https://leetcode.com/problems/count-elements-with-maximum-frequency/description/?envType=daily-question&envId=2024-02-23

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int>mp;
        for (int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int maxFreq = 1;
        for (auto ele : mp){
            if (ele.second>maxFreq){
                maxFreq = ele.second;
            }
        }
        for (auto ele : mp){
            if (ele.second == maxFreq){
                ans += maxFreq;
            }
        }
        return ans;
    }
};