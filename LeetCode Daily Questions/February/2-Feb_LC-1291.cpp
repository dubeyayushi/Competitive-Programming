// https://leetcode.com/problems/sequential-digits/description/

class Solution {
public:
    void f(int low, int high, vector<int>&ans, int i){
        if (i>=low && i<=high){
            ans.push_back(i);
        }
        if (i>high || i%10==9){
            return;
        }
        f(low, high, ans, i*10 + ((i%10)+1));
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for (int i = 1; i<9; i++){
            f(low, high, ans, i);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};