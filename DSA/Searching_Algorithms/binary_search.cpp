#include<iostream>
using namespace std;

int binarySearch(int *nums, int n, int val){
    int start = 0; 
    int end = n-1;
    while(start<=end){
        int mid = (start+end)/2;
        if (nums[mid]==val){
            return mid;
        }
        else if (nums[mid]>val){
            end = mid - 1;
            continue;
        }
        else{
            start = mid+1;
            continue;
        }
    }
    return -1;
}

int main(){
    int input[5] = {1,2,3,4,5};
    cout << binarySearch(input, 5, 15) << endl;
}