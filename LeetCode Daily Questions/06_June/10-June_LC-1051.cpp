// https://leetcode.com/problems/height-checker/description/

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>expected = heights;
        sort(expected.begin(), expected.end());
        int ans = 0;
        for (int i = 0; i<expected.size(); i++){
            if (heights[i]!=expected[i]) ans++;
        }
        return ans;
    }
};