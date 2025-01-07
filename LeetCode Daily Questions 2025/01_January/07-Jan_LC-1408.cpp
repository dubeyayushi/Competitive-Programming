// https://leetcode.com/problems/string-matching-in-an-array/description/

class Solution {
public:
    bool checkSubstring(string a, string b){
        int n = a.length();
        for (int i = 0; i<b.length(); i++){
            string str = b.substr(i, n);
            if (str==a) return true;
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
        for (int i = 0; i<words.size(); i++){
            string word = words[i];
            for (int j = 0; j<words.size(); j++){
                if (i==j || word.length()>=words[j].length()) continue;
                if (checkSubstring(word, words[j])){
                    ans.push_back(word);
                    break;
                } 
            }
        }
        return ans;
    }
};