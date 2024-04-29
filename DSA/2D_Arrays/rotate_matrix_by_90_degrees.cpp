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
    for (int i = 0; i<n/2; i++){
        for(int j = 0; j<m; j++){
            int temp = nums[j][i];
            nums[j][i] = nums[j][n-i-1];
            nums[j][n-i-1] = temp;
        }
    }

    cout << "The matrix after rotation is: " << endl;
    for (int i = 0; i<m; i++){
        for (int j = 0; j<n; j++){
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}