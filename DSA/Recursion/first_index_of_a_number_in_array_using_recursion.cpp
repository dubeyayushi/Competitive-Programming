#include<iostream>
using namespace std;

int firstIndex(int input[], int size, int x) {
    if (size == 0){
        return -1;
    }

    if (input[0]==x){
        return 0;
    }

    int smallOutput = firstIndex(input+1, size-1, x);
    if (smallOutput == -1){
        return -1;
    }
    else{
        return smallOutput+1;
    }
}

int main(){
    int a[7] = {1,2,3,4,4,3,5};

    cout << firstIndex(a, 7, 10) << endl;
}