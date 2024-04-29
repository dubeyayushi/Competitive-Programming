#include<iostream>
#include<vector>
using namespace std;
 
int main(){
    string s = "peaaaceeee";

    vector<int> v(26, 0);

    for (int i = 0; i<s.length(); i++){
        int val = (int)s[i];
        v[val-97]++;
    }

    int max = 0;
    char ch;

    for (int i = 0; i<26; i++){
        if (v[i]>max){
            max = v[i];
            ch = i+97;
        }
    }

    cout << ch << " " << max << endl;
}