#include<iostream>
using namespace std;
 
int main(){
    int arr[] = {4, 1, 3, 4, 5, 2, 1, 3, 5};
    int n = 9;
    int res = 0;
    for (int i = 0; i<n; i++){
        res = res ^ arr[i];
    }
    cout << res << endl;
}