#include <iostream>
#include <vector>
#define ll long long int
using namespace std;

vector<vector<vector<ll> > >dp;

ll f(vector<int> &a, vector<int> &b, int n, int m, int i, int j, int k){
	if (n==i || m==j){
		return 0;
	}
	if (dp[i][j][k]!=-1){
		return dp[i][j][k];
	}
	ll res = 0;
	if (a[i]==b[j]){
		res = 1 + f(a, b, n, m, i+1, j+1, k);
	}
	else{
		if (k>0){
			res = 1 + f(a, b, n, m, i+1, j+1, k-1);
		}
		res = max(res, f(a, b, n, m, i+1, j, k));
		res = max(res, f(a, b, n, m, i, j+1, k));
	}
	return dp[i][j][k] = res;
}

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<int>a(n);
	vector<int>b(m);
	for (int i = 0; i<n; i++){
		cin >> a[i];
	}
	for (int i = 0; i<m; i++){
		cin >> b[i];
	}
	dp.clear();
	dp.resize(n+1, vector<vector<ll> >(m+1, vector<ll>(k+1, -1)));
	cout << f(a, b, n, m, 0, 0, k);
}
