// https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=count-number-of-substrings

class Solution
{
  public:
    
    long long helper(string s, int n, int x){
        long long count = 0;
        int i = 0;
        int j = 0;
        vector<int>charFreq(26, 0);
        
        int f = 0;
        for (i = 0; i<n; i++){
            while(j<n && f<x){
                charFreq[s[j]-97]++;
                if(charFreq[s[j]-97]==1){
                    f++;
                }
                j++;
            }
            if (f>=x){
                count = count + n - j + 1;
            }
            charFreq[s[i]-97]--;
            if (charFreq[s[i]-97] == 0){
                f--;
            }
        }
        return count;
    }
    
    long long int substrCount (string s, int k) {
    	//code here.
    	int n = s.length();
    	long long int ans = helper(s, n, k) - helper(s, n, k+1);
    	return ans;
    }
};