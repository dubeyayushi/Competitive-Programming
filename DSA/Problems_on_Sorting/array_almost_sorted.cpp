#include<iostream>
using namespace std;
 
int main(){
    int n;
    cout << "Enter the number of elements in the array:";
    cin >> n;
    int arr[n];
    cout << "Enter the elements:" << endl;
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }
    int count = 0;
    for (int i = 0; i<n-1; i++){
        if (arr[i]>arr[i+1]){
            count++;
        }
    }
    if(count >1){
        cout << "false" << endl;
    }
    else{
        cout << "true" << endl;
    }
}