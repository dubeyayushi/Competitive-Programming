// https://leetcode.com/problems/assign-cookies/description/?envType=daily-question&envId=2024-01-01

#include<iostream>
#include<vector>
using namespace std;
 
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int i = 0;
        int j = 0;
        while(i<g.size() && j<s.size()){
            if (s[j]>=g[i]){
                count++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return count;
    }
};