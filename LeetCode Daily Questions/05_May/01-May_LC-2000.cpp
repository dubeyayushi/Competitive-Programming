// https://leetcode.com/problems/reverse-prefix-of-word/description/

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = 0;
        for (int i = 0; i<word.length(); i++){
            if (word[i]==ch){
                idx = i;
                break;
            }
        }
        for (int i = 0; i<=idx/2; i++){
            swap(word[i], word[idx-i]);
        }
        return word;
    }
};