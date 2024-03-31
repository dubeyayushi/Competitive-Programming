// https://leetcode.com/problems/intersection-of-two-arrays/description/?envType=daily-question&envId=2024-02-23

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1;
        set<int>s2;
        vector<int>ans;
        for (int i = 0; i<nums1.size(); i++){
            s1.insert(nums1[i]);
        }
        for (int i = 0; i<nums2.size(); i++){
            s2.insert(nums2[i]);
        }
        if (s1.size()>s2.size()){
            for (auto ele : s2){
                if (s1.find(ele)!=s1.end()){
                    ans.push_back(ele);
                }
            }
        }
        else{
            for (auto ele : s1){
                if (s2.find(ele)!=s2.end()){
                    ans.push_back(ele);
                }
            }
        }
        return ans;
    }
};