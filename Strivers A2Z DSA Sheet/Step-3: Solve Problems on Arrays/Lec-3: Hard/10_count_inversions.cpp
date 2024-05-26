// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=inversion-of-array

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[], int start, int mid, int end){
        vector<long long>temp;
        int left = start; 
        int right = mid+1;
        long long count = 0;
        
        while(left<=mid && right<=end){
            if (arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                count += mid-left+1;
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=end){
            temp.push_back(arr[right]);
            right++;
        }
        for (int i = start; i<=end; i++){
            arr[i] = temp[i-start];
        }
        return count;
    }
    long long int mergeSort(long long arr[], int start, int end){
        long long count = 0;
        if (start>=end) return count;
        int mid = (start + (end-start)/2);
        count += mergeSort(arr, start, mid);
        count += mergeSort(arr, mid+1, end);
        count += merge(arr, start, mid, end);
        return count;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return mergeSort(arr, 0, N-1);
    }

};