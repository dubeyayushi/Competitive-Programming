// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=leaders-in-an-array

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        vector<int>ans;
        ans.push_back(a[n-1]);
        int maxele = a[n-1];
        for (int i = n-2; i>=0; i--){
            if (a[i]>=maxele){
                ans.push_back(a[i]);
                maxele = a[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};