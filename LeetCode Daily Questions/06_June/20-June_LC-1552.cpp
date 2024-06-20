// https://leetcode.com/problems/magnetic-force-between-two-balls/description/

class Solution {
public:
    bool check(int gap, vector<int>& position, int m){
        int prevPos = position[0];
        int count = 1;
        for (int i = 0; i<position.size(); i++){
            if (position[i] - prevPos >= gap){
                prevPos = position[i];
                count += 1;
            }
        }
        return count >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        int ans = 0;
        int n = position.size();
        sort(position.begin(), position.end());
        int start = 1;
        int end = (position[n-1]%(m-1)) ? (position[n-1]/(m-1)) + 1 : (position[n-1]/(m-1));
        cout << end << endl;
        while(start<=end){
            int mid = start + (end-start)/2;
            if (check(mid, position, m)){
                ans = max(ans, mid);
                start = mid+1;
            }
            else{
                end = mid-1; 
            }
        }
        return ans;
    }
};