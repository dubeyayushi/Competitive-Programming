// https://leetcode.com/problems/intersection-of-two-arrays-ii/description/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>result;
        unordered_map<int, int>mp1;
        unordered_map<int, int>mp2;
        for (int i = 0; i<nums1.size(); i++){
            mp1[nums1[i]]++;
        }
        for (int i = 0; i<nums2.size(); i++){
            mp2[nums2[i]]++;
        }
        for (auto ele : mp1){
            if (mp2.find(ele.first)!=mp2.end()){
                int val = min(ele.second, mp2[ele.first]);
                for (int i = 0; i<val; i++){
                    result.push_back(ele.first);
                }
            }
        }
        return result;
    }
};