#include<iostream>
using namespace std;

int multiplyNumbers(int m, int n) {
    if (n==0){
        return 0;
    }

    int smallOutput = multiplyNumbers(m, n-1);
    int output = m+smallOutput;
    return output;
}
int main(){
    int m, n;
    cin >> m >> n;
    cout << multiplyNumbers(m,n);
}