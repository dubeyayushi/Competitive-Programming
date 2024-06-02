// https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1

class Solution {
  public:
    
    bool check(long double dist, vector<int> &stations, int k){
        int stationCount = 0;
        for (int i = 1; i<stations.size(); i++){
            int numberInBetween = ((stations[i]-stations[i-1])/dist);
            if ((stations[i]-stations[i-1])/dist == numberInBetween * dist){
                numberInBetween--;
            }
            stationCount += numberInBetween;
            if (stationCount>k) return false;
        }
        return true;
    }
  
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        long double start = 0;
        long double end = 0;
        for (int i = 0; i<stations.size()-1; i++){
            end = max(end, (long double)stations[i+1]-stations[i]);
        }
        long double diff = 1e-6;
        while(end-start > diff){
            long double mid = start + (end-start)/2.0;
            if (check(mid, stations, k)){
                end = mid;
            }
            else{
                start = mid;
            }
        }
        return end;
    }
};