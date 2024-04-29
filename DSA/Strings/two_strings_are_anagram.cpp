#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
 
int main(){
    string s = "learning dsa";
    string t = "dsalearning ";

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    if (s==t){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}