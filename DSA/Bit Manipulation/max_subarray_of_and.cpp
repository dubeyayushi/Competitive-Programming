#include<iostream>
#include<climits>
using namespace std;
 
int max_subarray_of_and(int* arr, int n){
    int maxele = INT_MIN;
    int ans = 0;
    for (int i = 0; i<n; i++){
        if (arr[i]>maxele){
            maxele = arr[i];
            ans=1;
        }
        else if (arr[i]==maxele){
            ans++;
        }
    }
    return ans;
}

int main(){
    int arr[] = {12, 1, 2, 3, 4, 5, 6, 6, 6, 2, 13, 13, 13, 13, 18, 1};
    int n = 15;
    cout << max_subarray_of_and(arr, n) << endl;
}