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

    for (int i = 0; i<m; i++){
        for (int j = i; j<n; j++){
            int temp = nums[i][j];
            nums[i][j] = nums[j][i];
            nums[j][i] = temp;
        }
    }
    cout << "The transpose of the matrix is: " << endl;
    for (int i = 0; i<m; i++){
        for (int j = 0; j<n; j++){
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}