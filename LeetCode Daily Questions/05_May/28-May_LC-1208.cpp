// https://leetcode.com/problems/get-equal-substrings-within-budget/description/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int start = 0;
        int current_cost = 0;
        int max_length = 0;
        for (int end = 0; end<s.length(); end++){
            current_cost += abs(s[end]-t[end]);
            while (current_cost > maxCost){
                current_cost -= abs(s[start]-t[start]);
                start++;
            }
            max_length = max(end-start+1, max_length);
        }
        return max_length;
    }
};