#include<iostream>
using namespace std;
 
int main(){
    string arr[] = {"00123", "0233", "234", "9453"};

    long long max = stoll(arr[0]);

    for (int i = 1; i<4; i++){
        if (stoll(arr[i])>max){
            max = stoll(arr[i]);
        }
    }

    cout << max;
}