// https://leetcode.com/problems/count-vowel-strings-in-ranges/description/

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>ans;
        set<char>s = {'a', 'e', 'i', 'o', 'u'};
        vector<int>prefixSum(words.size(), 0);
        if (s.find(words[0][0])!=s.end() && s.find(words[0][words[0].length()-1])!=s.end()){
            prefixSum[0]++;
        }
        for (int i = 1; i<words.size(); i++){
            string word = words[i];
            int n = word.length()-1;
            if (s.find(word[0])!=s.end() && s.find(word[n])!=s.end()){
                prefixSum[i] = prefixSum[i-1]+1;
            }
            else{
                prefixSum[i] = prefixSum[i-1];
            }
        }
        for (auto q : queries){
            int l = q[0];
            int r = q[1];
            if (l == 0) {
                ans.push_back(prefixSum[r]);
            } else {
                ans.push_back(prefixSum[r] - prefixSum[l - 1]);
            }
        }
        return ans;
    }
};