#include<iostream>
#include<vector>
using namespace std;

void binaryStrings(int n, string s){
    if (s.length()==n){
        cout << s << endl;
        return;
    }
    binaryStrings(n, s+'0');
    if (s.length()==0 || s[s.length()-1]=='0'){
        binaryStrings(n, s+'1');
    }
}

int main(){
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    binaryStrings(n, "");
}