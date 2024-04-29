#include<iostream>
using namespace std;
 
int max_power_of_2(int num){
    int temp;
    while(num>0){
        temp = num;
        num = num & (num-1);
    }
    return temp;
}

int main(){
    cout << max_power_of_2(24) << endl;
}