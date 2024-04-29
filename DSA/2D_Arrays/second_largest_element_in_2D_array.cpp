#include<iostream>
#include<climits>
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

    int first = nums[m-1][n-1], second = nums[m-1][n-2];
    for (int i = 0; i<m; i++){
        for (int j = 0; j<n; j++){
            if (nums[i][j]>first){
                first = nums[i][j];
            }
            else if (nums[i][j]>second && nums[i][j]<first){
                second = nums[i][j];
            }
        }
    }

    cout << "The second largest element is: " << second;
}