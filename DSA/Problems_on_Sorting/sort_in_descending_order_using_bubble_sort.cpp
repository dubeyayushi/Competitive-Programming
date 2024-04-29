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

    bool flag = true;
    for (int j = 0; j<n-1; j++){
        if (arr[j]<arr[j+1]){
            flag = false;
        }
    }
    for (int i = 0; i<n; i++){
        if (flag == true){
            cout << "Array already sorted" << endl;
            break;
        }
        else{
            for (int j = 0; j<n-1-i; j++){
                if (arr[j]<arr[j+1]){
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }
    for (int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }


}