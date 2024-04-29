#include<iostream>
#include<vector>
#include<climits>
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

    vector<int>v(n, 0);
    int mindx = -1;
    int x = 0;

    for (int i = 0; i<n; i++){
        int min = INT_MAX;
        for (int j = 0; j<n; j++){
            if (v[j]!=1){
                if (arr[j]<min){
                    min = arr[j];
                    mindx = j;
                }
            }
        }
        arr[mindx] = x;
        x++;
        v[mindx] = 1;
    }

    for (int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }

}