// https://leetcode.com/problems/trapping-rain-water/description/?envType=daily-question&envId=2024-04-12

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        //previous greatest element
        int prev[n];
        prev[0] = -1;
        int max = height[0];

        for (int i = 1; i<n; i++){
            prev[i] = max;
            if (max<height[i]){
                max = height[i];
            }
        }

        //next greatest element
        int next[n];
        next[n-1] = -1;
        max = height[n-1];

        for (int i = n-2; i>=0; i--){
            next[i] = max;
            if (max<height[i]){
                max = height[i];
            }
        }
        
        int min;
        int sum = 0;
        for (int i = 0; i<n; i++){
            if (prev[i]<=next[i]){
                min = prev[i];
            }
            else{
                min = next[i];
            }

            if (height[i]<min){
                sum += (min - height[i]);
            }
        }
        return sum;
    }
};