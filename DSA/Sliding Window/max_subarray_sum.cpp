#include<iostream>
using namespace std;
 
int main(){
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int window_size;
    cout << "Enter size of the subarray: ";
    cin >> window_size;

    int arr[size];
    cout << "Enter the elements in the array: " << endl;
    for (int i = 0; i<size; i++){
        cin >> arr[i];
    }

    int current_sum = 0;
    for (int i = 0; i<window_size; i++){
        current_sum += arr[i];
    }
    int maxSum = current_sum;
    int i = 1; 
    int j = window_size;
    while(j<size){
        current_sum = current_sum + arr[j] - arr[i-1];
        if (maxSum<current_sum){
            maxSum = current_sum;
        }
        i++;
        j++;
    }
    cout << "The maximum sum of the subarray is: " << maxSum << endl;
}