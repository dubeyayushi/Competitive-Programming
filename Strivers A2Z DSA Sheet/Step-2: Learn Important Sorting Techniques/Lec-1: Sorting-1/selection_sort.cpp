// https://www.naukri.com/code360/problems/selection-sort_624469?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

/*
    time complexity: 
        1. best case - O(n^2)
        2. average case - O(n^2)
        3. worst case - O(n^2)
*/


void selectionSort(vector<int>&arr) {
    // Write your code here.
    for (int i = 0; i<arr.size(); i++){
        for (int j = i+1; j<arr.size(); j++){
            if (arr[j]<arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}