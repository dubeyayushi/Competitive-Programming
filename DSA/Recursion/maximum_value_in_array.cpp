#include<iostream>
#include<climits>
using namespace std;
 
void printMaxValue(int* arr, int n, int max){
    if (n==0){
        cout << max << endl;
        return;
    }
    if (arr[0]>max){
        max = arr[0];
    }
    printMaxValue(arr+1, n-1, max); 
}

int storeMaxValue(int *arr, int n){
    if (n==0){
        return INT_MIN;
    }
    return max(arr[0], storeMaxValue(arr+1, n-1));
}

int main(){
    int n;
    cout << "Enter size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }
    printMaxValue(arr, n, INT_MIN);
    cout << storeMaxValue(arr, n) << endl;
}