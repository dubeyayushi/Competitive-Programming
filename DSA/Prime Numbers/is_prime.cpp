#include<iostream>
#include<cmath>
using namespace std;
 
bool is_prime(int n){
    if (n==1){
        return false;
    }
    for (int i = 2; i<=sqrt(n); i++){
        if (n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    bool isPrime;
    int n;
    cout << "Enter the number: ";
    cin >> n;
    isPrime = is_prime(n);
    cout << isPrime << endl;
}