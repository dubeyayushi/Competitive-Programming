//https://www.naukri.com/code360/problems/largest-element-in-the-array-largest-element-in-the-array_5026279?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    // Write your code here.
    int ans = INT_MIN;
    for (int i = 0; i<arr.size(); i++){
        if (arr[i]>ans){
            ans = arr[i];
        }
    }
    return ans;
}
