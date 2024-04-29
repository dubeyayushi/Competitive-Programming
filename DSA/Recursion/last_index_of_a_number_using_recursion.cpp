#include<iostream>
using namespace std;

int lastIndex(int input[], int size, int x) {
    if (size==0){
        return -1;
    }

    int smallOutput = lastIndex(input+1, size-1, x);
    if (smallOutput==-1){
        if (input[0]!=x){
            return -1;
        }
    }
    return smallOutput+1;

}

int main(){
    int a[] = {1,2,3,4,4,5,6,5};
    cout << lastIndex(a, 8, 10) << endl;
}