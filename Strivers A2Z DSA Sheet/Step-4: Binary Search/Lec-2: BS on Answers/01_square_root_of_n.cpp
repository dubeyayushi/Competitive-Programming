// https://www.geeksforgeeks.org/problems/square-root/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=square-root

class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        long long low = 0;
        long long high = x;
        long long ans = INT_MIN;
        while(low<=high){
            long long mid = low + (high-low)/2;
            if (mid*mid<=x){
                ans = max(ans, mid);
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};