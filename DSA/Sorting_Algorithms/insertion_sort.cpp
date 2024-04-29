#include<iostream>
using namespace std;
 
int main(){
    int n;
    cout << "Enter the number of elements in array:";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of array:" << endl;
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }

    for (int i = 1; i<n; i++){
        int j = i; 
        while(j>=1 && arr[j]<arr[j-1]){
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
    
    for (int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
}