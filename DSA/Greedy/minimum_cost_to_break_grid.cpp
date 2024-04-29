#include<iostream>
#include<vector>
using namespace std;
#define ll long long int

bool cmp(ll x, ll y){
    return x>y;
}

ll minCostToBreakGrid(int n, int m, vector<ll>&vertical, vector<ll>&horizontal){
   sort(vertical.begin(), vertical.end(), cmp); 
   sort(horizontal.begin(), horizontal.end(), cmp); 
   int hz = 1;
   int vr = 1;
   int h = 0;
   int v = 0;
   ll ans = 0;
   while(h<horizontal.size() && v<vertical.size()){
        if (vertical[v]>horizontal[h]){
            ans += vertical[v]*vr;
            hz++;
            v++;
        }
        else{
            ans += horizontal[h]*hz;
            vr++;
            h++;
        }
   }
   while(h<horizontal.size()){
        ans += horizontal[h]*hz;
        vr++;
        h++;
   }
   while(v<vertical.size()){
        ans += vertical[v]*vr;
        hz++;
        v++;
   }
    return ans;
}

int main(){
    int n, m;
    cout << "Enter the number of vertical and horizontal edges" << endl;
    cin >> m >> n;
    vector<ll>horizontal, vertical;
    cout << "Enter the elements of the vertical vector " << endl;
    for (int i = 0; i<m-1; i++){
        ll x;
        cin >> x;
        vertical.push_back(x);
    }
    cout << "Enter the elements of the horizontal vector " << endl;
    for (int i = 0; i<n-1; i++){
        ll x;
        cin >> x;
        horizontal.push_back(x);
    }
    cout << minCostToBreakGrid(n, m, vertical, horizontal) << endl;
}