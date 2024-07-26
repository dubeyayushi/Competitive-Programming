#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void solve(const vector<vector<int> > &prefixFreqA, const vector<vector<int> > &prefixFreqB, int l, int r) {
    vector<int> freqA(26, 0), freqB(26, 0);

    for (int i = 0; i < 26; ++i) {
        freqA[i] = prefixFreqA[r + 1][i] - prefixFreqA[l][i];
        freqB[i] = prefixFreqB[r + 1][i] - prefixFreqB[l][i];
    }

    int changes = 0;
    for (int i = 0; i < 26; ++i) {
        changes += abs(freqA[i] - freqB[i]);
    }

    cout << changes / 2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string a, b;
        cin >> a >> b;

        vector<vector<int> > prefixFreqA(n + 1, vector<int>(26, 0));
        vector<vector<int> > prefixFreqB(n + 1, vector<int>(26, 0));

        for (int i = 0; i < n; ++i) {
            prefixFreqA[i + 1] = prefixFreqA[i];
            prefixFreqB[i + 1] = prefixFreqB[i];
            prefixFreqA[i + 1][a[i] - 'a']++;
            prefixFreqB[i + 1][b[i] - 'a']++;
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            solve(prefixFreqA, prefixFreqB, l - 1, r - 1);
        }
    }

    return 0;
}
