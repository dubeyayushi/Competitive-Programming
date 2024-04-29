#include<iostream>
using namespace std;

int main(){
    int m, n;
    cout << "Enter order of first matrix: ";
    cin >> m >> n;

    int p, q;
    cout << "Enter order of second matrix: ";
    cin >> p >> q;

    if (m==p && n==q){
        int nums1[m][n];
        int nums2[p][q];
        int res[m][n];
        cout << "Enter elements of first matrix: ";
        for (int i = 0; i<m; i++){
            for (int j = 0; j<n; j++){
                cin >> nums1[i][j];
            }
        }
        cout << "Enter elements of second matrix: ";
        for (int i = 0; i<p; i++){
            for (int j = 0; j<q; j++){
                cin >> nums2[i][j];
            }
        }

        for (int i = 0; i<m; i++){
            int sum = 0;
            for (int j = 0; j<n; j++){
                res[i][j] = nums1[i][j] + nums2[i][j];
            }
        }

        for (int i = 0; i<m; i++){
            for (int j = 0; j<n; j++){
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }

    else{
        cout << "Addition is not possible." <<endl;
    }
}