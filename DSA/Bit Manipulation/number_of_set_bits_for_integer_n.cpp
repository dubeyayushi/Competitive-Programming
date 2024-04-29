#include<iostream>
using namespace std;
 
int count_set_bits(int num){
    return __builtin_popcount(num);
}

int count_set_bits2(int num){
    int count = 0;
    while(num>0){
        count++;
        num = (num & (num-1));
    }
    return count;
}

int main(){
    //using inbuilt function - __builtin_popcount
    cout << count_set_bits(15) << endl;
    //without using inbuilt function
    cout << count_set_bits2(16) << endl;
}