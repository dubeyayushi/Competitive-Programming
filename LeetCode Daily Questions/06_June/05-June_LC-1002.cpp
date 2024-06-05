// https://leetcode.com/problems/find-common-characters/description/

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        vector<int>freqArr(26, 0);
        for (int i = 0; i<words[0].length(); i++){
            freqArr[words[0][i] - 'a']++;
        }
        for (int i = 0; i<words.size(); i++){
            vector<int>wordFreq(26, 0);
            for (int j = 0; j<words[i].length(); j++){
                wordFreq[words[i][j] - 'a']++;
            }
            for (int k = 0; k<26; k++){
                freqArr[k] = min(freqArr[k], wordFreq[k]);
            }
        }
        for (int i = 0; i<26; i++){
            string s(1, i + 'a'); 
            for (int j = 0; j < freqArr[i]; j++) {
                ans.push_back(s);
            }
        }
        return ans;
    }
};