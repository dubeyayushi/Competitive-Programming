#include<iostream>
using namespace std;
 
int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }

    int i = 0;
    while(i<n){
        int correctIdx = arr[i] - 1;
        if (i==correctIdx){
            i++;
        }
        else{
            swap(arr[i], arr[correctIdx]);
        }
    }
    cout << "The sorted array is: " << endl;
    for (int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
}