// https://leetcode.com/problems/boats-to-save-people/description/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        sort(people.begin(), people.end());
        int i = 0;
        int j = people.size()-1;
        while(i<=j){
            if (i==j){
                ans++;
                break;
            }
            int weight = people[i]+people[j];
            if (weight>limit){
                ans++;
                j--;
            }
            else{
                ans++;
                i++;
                j--;
            }
        }
        return ans;
    }
};