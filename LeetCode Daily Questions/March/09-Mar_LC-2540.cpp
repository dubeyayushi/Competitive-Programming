// https://leetcode.com/problems/minimum-common-value/description/?envType=daily-question&envId=2024-02-23

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0; i<nums1.size(); i++){
            for (int j = 0; j<nums2.size(); j++){
                if (nums1[i]==nums2[j]) return nums1[i];
                else if (nums1[i]<nums2[j]) break;
            }
        }
        return -1;
    }
};