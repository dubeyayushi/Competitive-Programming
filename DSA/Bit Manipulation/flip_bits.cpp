#include<iostream>
using namespace std;
 
int flip_bits(int num){
    int temp = num;
    temp = temp | (temp>>1);
    temp = temp | (temp>>2);
    temp = temp | (temp>>4);
    temp = temp | (temp>>8);
    temp = temp | (temp>>16);
    return (temp ^ num);
}

int flip_bits2(int num){
    int temp;
    int n = num;
    while(n>0){
        temp = n;
        n = n & (n-1);
    }
    temp = (temp<<1)-1;
    return (num^temp);
}

int main(){
    int num = 16;
    cout << flip_bits(num) << endl;
    cout << flip_bits2(num) << endl;
}