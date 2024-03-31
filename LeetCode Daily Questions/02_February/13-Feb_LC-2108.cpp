// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/?envType=daily-question&envId=2024-02-13

class Solution {
public:
    bool checkPalindrome(string str){
        int i = 0;
        int j = str.length()-1;
        while(i<j){
            if (str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for (int i = 0; i<words.size(); i++){
            if (checkPalindrome(words[i])){
                return words[i];
            }
        }
        return "";
    }
};