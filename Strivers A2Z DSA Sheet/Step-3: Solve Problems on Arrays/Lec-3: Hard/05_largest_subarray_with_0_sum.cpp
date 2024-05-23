// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1?category%5B%5D=Hash&company%5B%5D=Amazon&page=1&query=category%5B%5DHashcompany%5B%5DAmazonpage1company%5B%5DAmazoncategory%5B%5DHash&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=largest-subarray-with-0-sum

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int ans = 0;
        int sum = 0;
        unordered_map<int, int>mp;
        for (int i = 0; i<n; i++){
            sum += A[i];
            if (sum==0){
                ans = max(ans, i+1);
            }
            else if (mp.find(sum)==mp.end()){
                mp[sum] = i;
            }
            else{
                ans = max(ans, i-mp[sum]);
            }
        }
        return ans;
    }
};