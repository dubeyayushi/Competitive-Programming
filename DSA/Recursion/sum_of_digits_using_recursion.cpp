#include<iostream>
using namespace std;

int sumOfDigits(int n) {
    if (n==0){
        return 0;
    }

    int smallOutput = n%10 + sumOfDigits(n/10);
    return smallOutput;
} 

int main(){
    cout << sumOfDigits(0000) << endl;
}