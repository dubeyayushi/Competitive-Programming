// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/?envType=daily-question&envId=2024-01-01 

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        vector<int>v(bank.size(), 0);
        for (int i = 0; i<bank.size(); i++){
            for (int j = 0; j<bank[i].size(); j++){
                if (bank[i][j]=='1'){
                    v[i]++;
                }
            }
        }
        int i = 0;
        int j = i+1;
        while(j<v.size()){
            if ((v[i]==0 && v[j]==0)){
                i++;
                j++;
            }
            else if (v[i]==0){
                i++;
            }
            else if ((v[j]==0) || (i==j)){
                j++;
            }
            else{
                ans = ans + (v[i]*v[j]);
                i++;
                j++;
            }
        }
        return ans;
    }
};