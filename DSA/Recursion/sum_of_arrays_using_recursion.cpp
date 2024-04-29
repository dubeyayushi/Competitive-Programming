#include<iostream>
using namespace std;


int sum(int input[], int n) {
    if (n == 0 ){
        return 0;
    }
    if (n == 1){
        return input[0];
    }

    int smallOutput1 = input[0]+ sum(input+1, n-1);
    return (smallOutput1);
}

int main(){
    int a[4] = {1,2,3,4};
    cout << sum(a, 4) << endl;
    
}