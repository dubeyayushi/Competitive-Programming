#include<iostream>
using namespace std;
 
int oddSum (int a, int b){
    int sum = b;
    if (b<a){
        return 0;
    }
    sum = sum + oddSum(a, b-1);
    return sum;
}

int main(){
    int a, b;
    cout << "Enter a and b: ";
    cin >> a >> b;
    cout << "Sum: " << oddSum(a, b);
}