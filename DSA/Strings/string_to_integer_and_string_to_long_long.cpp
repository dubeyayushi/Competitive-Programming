#include<iostream>
using namespace std;
 
int main(){
    string s = "123456";
    int a = stoi(s);    //stoi stands for string to integer
    string s1 = "123456789123456789";
    long long b = stoll(s1);  //stoll stands for string to long long

    cout << a << " " << b << endl;
}