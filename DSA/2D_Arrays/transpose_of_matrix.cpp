#include<iostream>
using namespace std;
 
int main(){
    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    int nums[m][n];

    for (int i= 0; i<m; i++){
        for (int j = 0; j<n; j++){
            cin >> nums[i][j];
        }
    }

    int transpose[n][m];
    for (int i = 0; i<m; i++){
        for (int j = 0; j<n; j++){
            transpose[j][i] = nums[i][j];
        }
    }

    cout << "The transpose of the matrix is: " << endl;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
}