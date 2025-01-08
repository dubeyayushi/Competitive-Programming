// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/

class Solution {
public:
    bool check(string word1, string word2){
        int n = word1.length();
        string prefix = word2.substr(0, n);
        string suffix = word2.substr(word2.length()-n, n);
        if (prefix==word1 && suffix==word1) return true;
        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for (int i = 0; i<words.size(); i++){
            for (int j = i+1; j<words.size(); j++){
                if (words[i].length()<=words[j].length() && check(words[i], words[j])) ans++;
            }
        }
        return ans;
    }
};