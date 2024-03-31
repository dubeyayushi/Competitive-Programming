// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=daily-question&envId=2024-02-23

bool cmp(vector<int>&a, vector<int>&b){
    if (a[1]<b[1]){
        return true;
    }
    return false;
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int overlap = 0;
        int lastEndPoint = points[0][1];
        for (int i = 1; i<points.size(); i++){
            if (points[i][0]<=lastEndPoint){
                overlap++;
            }
            else{
                lastEndPoint = points[i][1];
            }
        }
        return points.size() - overlap;
    }
};