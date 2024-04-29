#include<iostream>
using namespace std;

void traverse(int* arr, int n){
    if (n==0){
        return;
    }
    cout << arr[0] << endl;
    traverse(arr+1, n-1);
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
    traverse(arr, n);
}