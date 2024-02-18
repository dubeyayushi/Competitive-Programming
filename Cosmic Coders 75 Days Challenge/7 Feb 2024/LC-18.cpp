// https://leetcode.com/problems/4sum/description/

#define ll long long int
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        for (int i = 0; i<n-3; i++){
            for (int j = i+1; j<n-2; j++){
                ll newTarget = (ll)target - (ll)nums[i] - (ll)nums[j];
                int low = j+1;
                int high = n-1;
                while(low<high){
                    if (nums[low] + nums[high] < newTarget){
                        low++;
                    }
                    else if (nums[low] + nums[high] > newTarget){
                        high--;
                    }
                    else{
                        ans.push_back({nums[i], nums[j], nums[low], nums[high]});
                        int tempIdx1 = low, tempIdx2 = high;
                        while(low < high && nums[low] == nums[tempIdx1]) low++;
                        while(low < high && nums[high] == nums[tempIdx2]) high--;
                    }
                }
                while(j+1 < n && nums[j] == nums[j+1]) j++;
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};