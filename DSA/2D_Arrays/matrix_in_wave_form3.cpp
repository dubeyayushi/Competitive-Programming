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

    for (int j = 0; j<n; j++){
        if (j%2==0){
            for (int i = 0; i<m; i++){
                cout << nums[i][j] << " ";
            }
            cout << endl;
        }
        else{
            for (int i = m-1; i>=0; i--){
                cout << nums[i][j] << " ";
            }
            cout << endl;
        }
    }
}