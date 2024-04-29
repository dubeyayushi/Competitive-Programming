#include<iostream>
#include<stack>

using namespace std;
 
int main(){
    int arr[] = {2,1,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans[n];
    ans[n-1] = -1;
    stack<int>st;
    st.push(arr[n-1]);
    for (int i = n-2; i>=0; i--){
        while(st.size()>0 && st.top()<=arr[i]){
            st.pop();
        }
        if (st.size()==0){
            ans[i] = -1;
        }
        else{
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    for (int i = 0; i<n; i++){
        cout << ans[i] << " ";
    }
}