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

    int ans[size-window_size+1];

    int p = -1;
    for (int i = 0; i<window_size; i++){
        if (arr[i]<0){
            p = i;
            break;
        }
    }
    if (p==-1){
        ans[0] = 1;
    }
    else{
        ans[0] = arr[p];
    }
    int i = 1; 
    int j = window_size;
    while(j<size){
        if (p>=i){
            ans[i] = arr[p];
        }
        else{
            p = -1;
            for (int k = i; k<=j; k++){
                if (arr[k]<0){
                    p = k;
                    break;
                }
            }
            if (p==-1){
                ans[i] = 1;
            }
            else{
                ans[i] = arr[p];
            }
        }
        i++;
        j++;
    }
    for (int a = 0; a<size-window_size+1; a++){
        cout << ans[a] << " ";
    }
}