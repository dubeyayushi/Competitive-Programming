// https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-occurrence

class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int firstPos = -1;
	    int lastPos = -1;
	    
	    int start = 0;
	    int end = n-1;
	    
	    while(start<=end){
	        int mid = start + (end-start)/2;
	        if (arr[mid]==x){
	            if (mid==0){
	                firstPos = mid;
	                break;
	            }
	            else if (arr[mid-1]==x){
	                end = mid-1;
	            }
	            else{
	                firstPos = mid;
	                break;
	            }
	        }
	        else if (arr[mid]>x){
	            end = mid-1;
	        }
	        else{
	            start = mid+1;
	        }
	    }
	    
	    start = 0;
	    end = n-1;
	    while(start<=end){
	        int mid = start + (end-start)/2;
	        if (arr[mid]==x){
	            if (mid==n-1){
	                lastPos = mid;
	                break;
	            }
	            else if (arr[mid+1]==x){
	                start = mid+1;
	            }
	            else{
	                lastPos = mid;
	                break;
	            }
	        }
	        else if (arr[mid]>x){
	            end = mid-1;
	        }
	        else{
	            start = mid+1;
	        } 
	    }
	    if (firstPos==-1 || lastPos==-1) return 0;
	    return (lastPos - firstPos + 1);
	}
};