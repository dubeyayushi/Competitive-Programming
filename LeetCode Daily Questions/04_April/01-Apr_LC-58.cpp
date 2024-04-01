// https://leetcode.com/problems/length-of-last-word/description/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        for (int i = s.length()-1; i>=0; i--){
            if (s[i]!=' '){
                ans++;
            }
            else if (ans==0){
                continue;
            }
            else{
                break;
            }
        }
        return ans;
    }
};