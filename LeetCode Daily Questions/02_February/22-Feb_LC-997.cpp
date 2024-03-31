// https://leetcode.com/problems/find-the-town-judge/description/?envType=daily-question&envId=2024-02-22

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.size()==0 && n==1) return 1;
        if (trust.size()==0 && n!=1) return -1;
        if (trust.size()==1) return trust[0][1];
        unordered_map<int, int>mp;
        for (int i = 0; i<trust.size(); i++){
            mp[trust[i][1]]++;
        }
        for (auto ele : mp){
            if (ele.second==n-1){
                bool flag = true;
                for (int i = 0; i<trust.size(); i++){
                    if (trust[i][0]==ele.first){
                        flag = false;
                        break;
                    }
                }
                if (flag) return ele.first;
            };
        }
        return -1;
    }
};