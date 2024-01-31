//https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/?envType=daily-question&envId=2024-01-13

#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;
 
class Solution {
public:
    int minSteps(string s, string t) {
        int ans = 0;
        unordered_map<int, int>mp1;
        unordered_map<int, int>mp2;
        for (int i = 0; i<s.length(); i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        for (auto ele : mp2){
            char ch = ele.first;
            int freq = ele.second;
            if (mp1.find(ch)==mp1.end()){
                ans += freq;
            }
            else if (mp1[ch]<freq){
                ans = ans + (freq - mp1[ch]);
            }
        }
        return ans;
    }
};