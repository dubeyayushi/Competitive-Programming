#include<iostream>
using namespace std;
 
int main(){
    int n;
    cout << "Enter order of square matrix: ";
    cin >> n;

    int nums[n][n];

    cout << "Enter elements:" << endl;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            cin >> nums[i][j];
        }
    }

    int start = 0, end = n-1;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if (j==start || j==end){
                cout << nums[i][j] << " ";
            }
            else{
                cout << "  ";
            }
        }
        cout << endl;
        start++;
        end--;
    }
}