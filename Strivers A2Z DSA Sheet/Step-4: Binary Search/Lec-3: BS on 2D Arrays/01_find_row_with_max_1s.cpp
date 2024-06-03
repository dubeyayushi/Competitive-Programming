// https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=row-with-max-1s

class Solution{
public:
    int lowerBound(vector<vector<int> > arr, int row, int cols){
        int start = 0;
        int end = cols-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if (arr[row][mid]==1){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return start;
    }
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int ans = -1;
	    int countOnes = 0;
	    for (int i = 0; i<n; i++){
	        int count = m - lowerBound(arr, i, m);
	        if (countOnes<count){
	            countOnes = count;
	            ans = i;
	        }
	    }
	    return ans;
	}

};