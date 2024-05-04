// https://www.naukri.com/code360/problems/find-the-single-element_6680465?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

#include<vector>

int getSingleElement(vector<int> &arr){
	// Write your code here.
	for (int i = 0; i<arr.size(); i+=2){
          if (arr[i] != arr[i + 1]) {
            return arr[i];
        }
    }	
}