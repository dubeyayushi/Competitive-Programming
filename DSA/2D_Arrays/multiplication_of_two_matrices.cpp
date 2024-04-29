#include<iostream>
using namespace std;
 
int main(){
    int m, n;
    cout << "Enter order of first matrix: ";
    cin >> m >> n;

    int p, q;
    cout << "Enter order of second matrix: ";
    cin >> p >> q;

    if (n==p){
        int res[m][q];
        int nums1[m][n];
        int nums2[p][q];

        cout << "Enter the elements of first matrix:" << endl;
        for (int i = 0; i<m; i++){
            for (int j = 0; j<n; j++){
                cin >> nums1[i][j];
            }
        }
        cout << "Enter the elements of second matrix:" << endl;
        for (int i = 0; i<p; i++){                                   
            for (int j = 0; j<q; j++){
                cin >> nums2[i][j];
            }
        }

        for (int i = 0; i<m; i++){
            for (int j = 0; j<q; j++){
                res[i][j] = 0;
                for (int k = 0; k<n; k++){
                    res[i][j] += nums1[i][k]*nums2[k][j];
                    cout << res[i][j] << endl;
                }
            }
        }

        cout << "The matrix multiplication is:" << endl;
        for (int i = 0; i<m; i++){
            for (int j = 0; j<q; j++){
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "Multiplication of matrices is not possible" << endl;
    }

    
}