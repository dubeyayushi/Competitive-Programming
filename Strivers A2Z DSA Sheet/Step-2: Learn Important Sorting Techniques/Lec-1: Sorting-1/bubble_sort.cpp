// https://www.naukri.com/code360/problems/bubble-sort_624380?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

/*
    time complexity: 
        1. best case - O(n)
        2. average case - O(n^2)
        3. worst case - O(n^2)
*/


void bubbleSort(vector<int>& arr, int n) 
{
    //write your code here
    bool flag = true;
    for (int i = n-1; i>=0; i--){
        for (int j = 0; j<i; j++){
            if (arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag = false;
            }
        }
        if (flag) break;
    }
}