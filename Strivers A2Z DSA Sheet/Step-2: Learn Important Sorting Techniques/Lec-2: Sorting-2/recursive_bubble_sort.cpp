// https://www.naukri.com/code360/problems/bubble-sort_624380?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

/*
    time complexity: 
        1. best case - O(n)
        2. average case - O(n^2)
        3. worst case - O(n^2)
*/


void bubbleSort(vector<int>& arr, int n) 
{
    //write your code here
    if (n==1) return;

    for (int j = 0; j<n-1; j++){
        if (arr[j]>arr[j+1]){
            swap(arr[j], arr[j+1]);
        }
    }
    bubbleSort(arr, n-1);
}