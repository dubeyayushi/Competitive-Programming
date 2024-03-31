// https://leetcode.com/problems/custom-sort-string/description/?envType=daily-question&envId=2024-02-23

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int>mp;
        string ans = "";
        for (int i = 0; i<s.length(); i++){
            mp[s[i]]++;
        }
        for (int i = 0; i<order.length(); i++){
            if (mp.find(order[i])!=mp.end() && mp[order[i]]>0){
                for (int j = 0; j<mp[order[i]]; j++){
                    ans += order[i];
                }
                mp[order[i]] = 0;
            }
        }
        for (auto ele : mp){
            if (ele.second>0){
                for (int j = 0; j<ele.second; j++){
                    ans += ele.first;
                }
            }
        }
        return ans;
    }
};