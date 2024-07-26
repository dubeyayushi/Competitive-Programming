#include <iostream>
#include <vector>

using namespace std;

void solve(const vector<vector<char> >& matrix, int n, int k) {
    int newSize = n / k;
    vector<vector<char> > result(newSize, vector<char>(newSize));
    
    for (int i = 0; i < newSize; ++i) {
        for (int j = 0; j < newSize; ++j) {
            result[i][j] = matrix[i * k][j * k];
        }
    }
    
    for (int i = 0; i < newSize; ++i) {
        for (int j = 0; j < newSize; ++j) {
            cout << result[i][j];
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k;
        vector<vector<char> > matrix(n, vector<char>(n));
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                cin >> matrix[x][y];
            }
        }
        solve(matrix, n, k);
    }
    
    return 0;
}
