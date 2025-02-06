// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/?envType=daily-question&envId=2025-02-05

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1==s2) return true;
        int count = 0;
        vector<int>diffIdx;
        for (int i = 0; i<s1.length(); i++){
            if (s1[i]!=s2[i]){
                count++;
                diffIdx.push_back(i);
            }
        }
        if (count!=2){
            return false;
        }
        int idx1 = diffIdx[0];
        int idx2 = diffIdx[1];
        swap(s2[idx1], s2[idx2]);
        if (s1==s2) return true;
        return false;
    }
};