#include<iostream>
#include<vector>
using namespace std;

void subarrayIterative(int* arr, int n){
    for (int i = 0; i<n; i++){
        for (int j = i; j<n; j++){
            for (int k = i; k<=j; k++){
                cout << arr[k];
            }
            cout << " ";
        }
        cout << endl;
    }

}

void subarrayRecursion(vector<int>v, int* arr, int n, int idx){
    if (idx == n){
        for (int i = 0; i<v.size(); i++){
            cout << v[i];
        }
        cout << endl;
        return;
    }
    subarrayRecursion(v, arr, n, idx+1);
    if (v.size()==0 || v[v.size()-1]==arr[idx-1]){
        v.push_back(arr[idx]);
        subarrayRecursion(v, arr, n, idx+1);
    }
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];

    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }

    vector<int>v;

    subarrayIterative(arr, n);
    subarrayRecursion(v, arr, n, 0);
}