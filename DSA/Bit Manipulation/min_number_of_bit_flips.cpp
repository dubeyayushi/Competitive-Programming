#include<iostream>
using namespace std;
 
int min_number_of_bit_flips(int num1, int num2){
    num2 = num1 ^num2;
    int count;
    count = __builtin_popcount(num2);
    return count;
}

int main(){
    int num1 = 23;
    int num2= 31;
    cout << min_number_of_bit_flips(num1, num2) << endl;
}