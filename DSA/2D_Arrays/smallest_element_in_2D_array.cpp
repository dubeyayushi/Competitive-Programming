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

    int min = nums[0][0];
    for (int i = 0; i<m; i++){
        for (int j = 0; j<n; j++){
            if (nums[i][j]<min){
                min = nums[i][j];
            }
        }
    }

    cout << "The smallest element is: " << min;
}