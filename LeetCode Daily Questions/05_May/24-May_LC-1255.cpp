// https://leetcode.com/problems/maximum-score-words-formed-by-letters/description/

class Solution {
public:
    int a[26], b[26], ans = 0;

    void helper(int idx, vector<string>& words, vector<int>& score){
        if (idx==words.size()){
            int sum = 0;
            for (int i = 0; i<26; i++){
                if (b[i]>a[i]) return;
                sum += score[i] * b[i];
            }
            ans = max(ans, sum);
            return;
        }
        helper(idx+1, words, score);
        for (auto i : words[idx]){
            b[i-'a']++;
        }
        helper(idx+1, words, score);
        for (auto i : words[idx]){
            b[i-'a']--;
        }
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for (char letter : letters){
            a[letter - 'a']++;
        }
        helper(0, words, score);
        return ans;
    }
};