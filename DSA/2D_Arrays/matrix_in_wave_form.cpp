#include<iostream>
using namespace std;
 
int main(){
    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    int nums[m][n];
    
    cout << "Enter the elements: "<< endl;
    for (int i= 0; i<m; i++){
        for (int j = 0; j<n; j++){
            cin >> nums[i][j];
        }
    }

    for (int i = 0; i<m; i++){
        if (i%2==0){
            for (int j = 0; j<n; j++){
                cout << nums[i][j] << " ";
            }
            cout << endl;
        }
        else{
            for (int j = n-1; j>=0; j--){
                cout << nums[i][j] << " ";
            }
            cout << endl;
        }
    }
}