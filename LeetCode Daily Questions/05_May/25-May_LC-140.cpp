// https://leetcode.com/problems/word-break-ii/description/

class Solution {
public:
    void backtrack(string& s, unordered_set<string>& wordSet, string& currentSentence, vector<string>& results, int idx){
        if (idx == s.length()){
            results.push_back(currentSentence);
            return;
        }
        for (int i = idx+1; i<=s.length(); i++){
            string word = s.substr(idx, i-idx);
            if (wordSet.find(word)!=wordSet.end()){
                string originalSentence = currentSentence;
                if (!currentSentence.empty()) currentSentence += " ";
                currentSentence += word;
                backtrack(s, wordSet, currentSentence, results, i);
                currentSentence = originalSentence;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>wordSet;
        for (int i = 0; i<wordDict.size(); i++){
            wordSet.insert(wordDict[i]);
        }
        vector<string>results;
        string currentSentence = "";
        backtrack(s, wordSet, currentSentence, results, 0);
        return results;
    }
};