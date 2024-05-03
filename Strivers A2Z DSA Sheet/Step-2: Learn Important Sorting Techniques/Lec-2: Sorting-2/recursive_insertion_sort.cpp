// https://www.naukri.com/code360/problems/insertion-sort_624381?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

void helper(int arr[], int i, int n){
    if (i==n) return;

    int j = i;
    while(j>0 && arr[j-1]>arr[j]){
        int temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
        j--;
    }
    helper(arr, i+1, n);
}

void insertionSort(int arr[], int n)
{
    //write your code here
    helper(arr, 0, n);
}