#include<iostream>
using namespace std;

bool checkNumber(int input[], int size, int x) {
    if (size==0){
        return false;
    }

    if (input[0]==x){
        return true;
    }
    
    int smallOutput = checkNumber(input+1, size-1, x);
    return smallOutput;
}

int main(){
    int a[4] = {1,2,3,4};
    cout << checkNumber(a, 4, 4) << endl;
}