// https://leetcode.com/problems/shifting-letters-ii/description/

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> diff(s.length(), 0);
        for (auto shift : shifts){
            int l = shift[0];
            int r = shift[1];
            int dir = shift[2];
            if (dir == 1){
                diff[l]++;
                if (r+1<s.length()){
                    diff[r+1]--;
                }
            }
            else{
                diff[l]--;
                if (r+1<s.length()){
                    diff[r+1]++;
                }
            }
        }
        string ans(s.length(), ' ');
        int cumulativeShift = 0;
        for (int i = 0; i < s.length(); i++) {
            cumulativeShift = (cumulativeShift + diff[i]) % 26;
            if (cumulativeShift < 0){
                cumulativeShift += 26;
            }
            ans[i] = 'a' + (s[i] - 'a' + cumulativeShift) % 26;
            
        }
        return ans;
    }
};