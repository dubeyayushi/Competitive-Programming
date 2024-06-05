// https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    vector<string>words;
    void storeWordInVector(string s, int start, int end){
        string word = "";
        for (int i = start; i<=end; i++){
            word += s[i];
        }
        words.push_back(word);
    }
    string reverseWords(string s) {
        string ans = "";
        int wordStart = -1;
        int wordEnd = -1;
        for (int i = 0; i<s.length(); i++){
            if (wordStart == -1 && s[i]!=' '){
                wordStart = i;
            }
            if (wordStart!=-1 && s[i]!=' '){
                if (i==s.length()-1) wordEnd = i;
                else if (s[i+1] == ' ') {
                    wordEnd = i;
                }
                if (wordStart!=-1 && wordEnd!=-1){
                    storeWordInVector(s, wordStart, wordEnd);
                    wordStart = -1;
                    wordEnd = -1;
                }
            }
        }
        for (int i = words.size()-1; i>=0; i--){
            if (i==0){
                ans += words[i];
            }
            else{
                ans += words[i] + " ";
            }
        }
        return ans;
    }
};