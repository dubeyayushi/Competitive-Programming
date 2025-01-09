// https://leetcode.com/problems/counting-words-with-a-given-prefix/description/

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = pref.length();
        int ans = 0;
        for (int i = 0; i<words.size(); i++){
            if (words[i].length()>=n){
                string str = words[i].substr(0, n);
                if (str == pref) ans++;
            }
        }
        return ans;
    }
};