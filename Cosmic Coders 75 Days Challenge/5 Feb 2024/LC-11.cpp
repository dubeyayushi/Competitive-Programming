// https://leetcode.com/problems/container-with-most-water/description/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = INT_MIN;
        int left = 0;
        int right = height.size()-1;
        while(left<right){
            int currArea = min(height[left], height[right]) * (right-left);
            ans = max(ans, currArea);

            if (height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return ans;
    }
};