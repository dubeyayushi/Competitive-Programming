// https://www.geeksforgeeks.org/problems/rotation4723/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotation

class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int minele = INT_MAX;
	    int minidx = -1;
	    int low = 0;
	    int high = n-1;
	    while(low<=high){
	        int mid = low + (high-low)/2;
	        if (low==high && high==mid){
	            if (arr[low]<minele){
	                minele = arr[low];
	                minidx = low;
	            }
	            break;
	        }
	        if (arr[mid]<minele){
	            minele = arr[mid];
	            minidx = mid;
	        }
	        if (arr[low]<arr[mid]){  // left half is sorted
	            if (arr[low]<minele){
	                minele = arr[low];
	                minidx = low;
	            }
	            low = mid+1;
	        }
	        else{
	            if (arr[mid+1]<minele){
	                minele = arr[mid+1];
	                minidx = mid+1;
	            }
	            high = mid-1;
	        }
	    }
	    return minidx;
	}

};