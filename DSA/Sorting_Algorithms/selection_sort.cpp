#include<iostream>
#include<climits>
using namespace std;
 
int main(){
    int n;
    cout << "Enter the size of the array:";
    cin >> n;

    int arr[n];
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }

    for (int i = 0; i<n-1; i++){
        int min = INT_MAX;
        int mindx = -1;
        for (int j = i; j<n; j++){
            if (arr[j]<min){
                min = arr[j];
                mindx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[mindx];
        arr[mindx] = temp;
    }
    for (int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
}