// https://leetcode.com/problems/neighboring-bitwise-xor/description/

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int val = 0;
        for (int i = 0; i<derived.size(); i++){
            val ^= derived[i];
        }
        if (val==0) return true;
        return false;
    }
};