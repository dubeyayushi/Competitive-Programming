// https://leetcode.com/problems/largest-divisible-subset/description/?envType=daily-question&envId=2024-02-09

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>maxLength(n, 1);
        vector<int>prevElement(n, -1);
        int maxIdx = 0;

        for (int i = 0; i<n; i++){
            for (int j = 0; j<i; j++){
                if (nums[i]%nums[j] == 0 && maxLength[i] < maxLength[j] + 1){
                    maxLength[i] = maxLength[j] + 1;
                    prevElement[i] = j;
                }
            }
            if (maxLength[i] > maxLength[maxIdx]){
                maxIdx = i;
            }
        }
        vector<int>ans;
        for (int i = maxIdx; i != -1; i = prevElement[i]){  
            ans.insert(ans.begin(), nums[i]);
        }
        return ans;

    }
};
