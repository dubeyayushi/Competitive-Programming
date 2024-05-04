// https://www.naukri.com/code360/problems/left-rotate-an-array-by-one_5026278?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
vector<int> rotateArray(vector<int>& arr, int n) {
    // Write your code here.
    int first = arr[0];
    for (int i = 1; i<n; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = first;
    return arr;
}
