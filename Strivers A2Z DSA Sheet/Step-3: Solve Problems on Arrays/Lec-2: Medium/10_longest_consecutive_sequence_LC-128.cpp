// https://leetcode.com/problems/longest-consecutive-sequence/description/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int ans = 1;
        unordered_set<int>s;
        for (int i = 0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        for (int ele : s){
            if (s.find(ele-1)==s.end()){
                int count = 1;
                int x = ele;
                while(s.find(x+1)!=s.end()){
                    x += 1;
                    count++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};