// https://leetcode.com/problems/bitwise-xor-of-all-pairings/description/?envType=daily-question&envId=2025-01-16

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, long long>mp;
        int ans = 0;
        int len1 = nums1.size();
        int len2 = nums2.size();

        for (int i = 0; i<len1; i++){
            mp[nums1[i]] += len2;
        }
        for (int i = 0; i<len2; i++){
            mp[nums2[i]] += len1;
        }
        for (auto ele : mp){
            if (ele.second % 2 != 0){
                ans ^= ele.first;
            }
        }
        return ans;
    }
};