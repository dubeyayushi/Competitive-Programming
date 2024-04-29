#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
 
float max(float a, float b){
    if (a>=b) return a;
    else return b;
}
float min(float a, float b){
    if (a<b) return a;
    else return b;
}

int main(){
    int n;
    cout << "Enter the number of elements in the array:";
    cin >> n;
    int arr[n];
    cout << "Enter the elements:" << endl;
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }

    float kmin = (float)INT_MIN;
    float kmax = (float)INT_MAX;
    bool flag = true;
    for (int i = 0; i<n; i++){
        if (arr[i]>=arr[i+1]){
            kmin = max(kmin, (arr[i]+arr[i+1])/2.0);
        }
        else{
            kmax = min(kmax, (arr[i]+arr[i+1])/2.0);
        }
        if (kmax<kmin){
            flag = false;
            break;
        }
    }
    if (flag == false){
        cout << -1 << endl;
    }
    else if(kmin==kmax){
        if (kmin-(int)kmin==0){
            cout << "There is only one value of k: " << kmin << endl;
        }
        else{
            cout << -1;
        }
    }
    else{
        if (kmin-(int)kmin>0){
            kmin = int(kmin)+1;
        }
        cout << "range of k is [" << kmin << ", " << (int)kmax << "]" << endl;
    }

}