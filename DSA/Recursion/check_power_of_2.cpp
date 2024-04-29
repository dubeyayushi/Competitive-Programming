#include<iostream>
using namespace std;
 
bool checkPowerOfTwo(int n){
    if (n==1){
        return true;
    }
    if (n%2==0){
        return checkPowerOfTwo(n/2);
    }
    else{
        return false;
    }
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << checkPowerOfTwo(n);
}