#include<iostream>
#include<vector>
using namespace std;
 
void removeDigit(vector<int> arr, int n, int num, vector<int> ans, int idx){
    if (idx==n){
        for (int i = 0; i<ans.size(); i++){
            cout << ans[i] << " ";
        }
        return;
    }
    if (arr[idx]==num){
        removeDigit(arr, n, num, ans, idx+1);
    }
    else{
        ans.push_back(arr[idx]);
        removeDigit(arr, n, num, ans, idx+1);
    }
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector <int> arr(n);
    vector <int> ans;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }
    int num;
    cout << "Enter the element to be removed: ";
    cin >> num;
    removeDigit(arr, n, num, ans, 0);
}