// https://leetcode.com/problems/word-subsets/description/

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26, 0);
        for (int i = 0; i<words2.size(); i++){
            vector<int>freq(26, 0);
            for (int j = 0; j<words2[i].length(); j++){
                freq[words2[i][j] - 'a']++;
            }
            for (int j = 0; j<26; j++){
                maxFreq[j] = max(maxFreq[j], freq[j]);
            }
        }
        vector<string>ans;
        for (int i = 0; i<words1.size(); i++){
            vector<int>freq(26, 0);
            bool isUniversal = true;
            for (int j = 0; j<words1[i].length(); j++){
                freq[words1[i][j] - 'a']++;
            }
            for (int j = 0; j<26; j++){
                if (freq[j] < maxFreq[j]){
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal){
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};