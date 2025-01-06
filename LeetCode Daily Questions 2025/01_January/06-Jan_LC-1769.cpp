// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>indices;
        for (int i = 0; i<boxes.length(); i++){
            if (boxes[i]=='1'){
                indices.push_back(i);
            }
        }
        vector<int>ans(boxes.length(), 0);
        for (int i = 0; i<ans.size(); i++){
            for (int idx : indices){
                ans[i] += abs(i - idx);
            }
        }
        return ans;
    }
};