#include<iostream>
#include<cmath>
using namespace std;

double geometricSum(int k) {
    if (k==0){
        return 1;
    }
    double smallOutput = geometricSum(k-1) + 1/pow(2,k);
    return smallOutput;
}

int main(){
    int k;
    cin >> k;
    cout << geometricSum(k) << endl;
}