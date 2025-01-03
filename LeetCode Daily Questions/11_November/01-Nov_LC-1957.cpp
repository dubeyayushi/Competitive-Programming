// https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/

class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int count = 1; 
        
        ans += s[0]; 
        
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                count = 1;
            }
            
            if (count <= 2) {
                ans += s[i];
            }
        }
        
        return ans;
    }
};
