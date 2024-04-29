#include<iostream>
#include<string>
#include<sstream>
using namespace std;
 
int main(){
    string str = "i am learning     dsa";
    stringstream ss(str);

    string temp;
    while(ss>>temp){
        cout << temp << endl;
    }

}