// https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=k-th-element-of-two-sorted-array

class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int idx = 0;
        int i = 0;
        int j = 0;
        while(i<n && j<m){
            int ele = -1;
            if (arr1[i]<arr2[j]){
                ele = arr1[i];
                i++;
            }
            else{
                ele = arr2[j];
                j++;
            }
            if (k==idx+1) return ele;
            idx++;
        }
        while(i<n){
            if (k==idx+1) return arr1[i];
            idx++;
            i++;
        }
        while(j<m){
            if (k==idx+1) return arr2[j];
            idx++;
            j++;
        }
        return -1;
    }
};