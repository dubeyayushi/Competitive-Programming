#include<iostream>
#include<queue>
#include<vector>
using namespace std;
 
int main(){
    int arr[] = {3, -4, -7, 30, 7, -9, 2, 1, 6, -1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    // -4 -4 -7 -9 -9 -9 0 -1 should be the answer
    for (int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    vector<int> ans;
    queue<int>q;
    for (int i = 0; i<n; i++){
        if (arr[i]<0){
            q.push(i);
        }
    }
    int i = 0;
    while (i+k<=n){
        while(q.size()>0 && q.front()<i){
            q.pop();
        }
        if (q.size()==0 || q.front()>=i+k){
            ans.push_back(0);
        }
        else{
            ans.push_back(arr[q.front()]);
        }
        i++;
    }
    for (int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;  
}
