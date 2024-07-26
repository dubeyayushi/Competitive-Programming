#include<iostream>
using namespace std;
 
void solve(int num){
    if (num%4==0){
        cout << num/4 << endl;
        return;
    } 
    int ans = 0;
    while(num){
        if (num>=4){
            ans++;
            num-=4;
        }
        else if (num>=2){
            ans++;
            num-=2;
        }
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    int arr[t];
    int i = 0;
    for (int i = 0; i < t; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < t; i++){
        solve(arr[i]);
    }
}