#include<iostream>
using namespace std;

//gcd are hcf are same
//gcd <= min(a, b)
//lcm >=max(a, b)

int gcdIterative(int a, int b){
    for (int i = min(a,b); i>=2; i--){
        if (a%i==0 && b%i==0){
            return i;
        }
    }
    return 1;
}

//long division method
//time complexity is log(a+b)
int gcdRecursive(int a, int b){
    if (b%a==0){
        return a;
    }
    return gcdRecursive(b%a, b);
}

int main(){
    int a, b;
    cout << "Enter the two numbers: ";
    cin >> a >> b;
    cout << gcdIterative(a, b) << endl;
    cout << gcdRecursive(a, b) << endl;
}