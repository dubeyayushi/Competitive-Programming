// https://www.naukri.com/code360/problems/insertion-sort_624381?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

/*
    time complexity: 
        1. best case - O(n)
        2. average case - O(n^2)
        3. worst case - O(n^2)
*/

void insertionSort(int arr[], int n)
{
    //write your code here
    for (int i = 0; i<n; i++){
        int j = i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}