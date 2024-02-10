// https://leetcode.com/problems/sort-characters-by-frequency/description/?envType=daily-question&envId=2024-02-07

class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char, int>mp;
        for (int i = 0; i<s.length();  i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int, char> >pq;
        for (auto ele : mp){
            int key = ele.first;
            int val = ele.second;
            pq.push({val, key});
        }
        while(pq.size()){
            pair<int, char> curr = pq.top();
            pq.pop();
            for (int i = 0; i<curr.first; i++){
                ans += curr.second;
            }
        }
        return ans;
    }

};