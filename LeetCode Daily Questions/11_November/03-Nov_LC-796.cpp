// https://leetcode.com/problems/rotate-string/description/

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length()!=goal.length()) return false;
        for (int shift = 0; shift<s.length(); shift++){
            if (s==goal) return true;
            char first = s[0];
            for (int i = 1; i<s.length(); i++){
                s[i-1] = s[i];
            }
            s[s.length()-1] = first;
        }
        return false;
    }
};