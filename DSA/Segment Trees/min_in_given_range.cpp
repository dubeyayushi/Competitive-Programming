#include<iostream>
#include<vector>
#include<climits>
using namespace std;
 
vector<int>st;

// O(n)
void buildTree(int arr[], int i, int lo, int hi){
    // base case
    if (lo==hi){
        st[i] = arr[lo];
        return;
    }
    int mid = lo + (hi-lo)/2;
    buildTree(arr, (2*i)+1, lo, mid);   // left subtree
    buildTree(arr, (2*i)+2, mid + 1, hi);   // right subtree
    st[i] = min(st[(2*i)+1], st[(2*i)+2]);

}

// O(logn)
int getMin(int i, int lo, int hi, int& l, int& r){
    if (r<lo || l>hi) return INT_MAX;
    if (lo>=l && hi<=r) return st[i];
    int mid = lo + (hi-lo)/2;
    return min(getMin(2*i+1, lo, mid, l, r), getMin(2*i+2, mid+1, hi, l, r));
}

int main(){
    int arr[] = {1, 4, 2, 8, 6, 4, 9, 3};
    int n = sizeof(arr)/4;
    st.resize(4*n);
    buildTree(arr, 0, 0, n-1);
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cout << endl << "Enter the range: ";
        cin >> l >> r;
        cout << getMin(0, 0, n-1, l, r) << endl;    //O(nlogn)
    }
}