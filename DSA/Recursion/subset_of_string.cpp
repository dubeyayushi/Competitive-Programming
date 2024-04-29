#include<iostream>
#include<string>
#include<vector>
using namespace std;
 
void stringSubset(string str, string ans, vector<string>&v){
    if (str==""){
        v.push_back(ans);
        return;
    }
    stringSubset(str.substr(1), ans+str[0], v);
    stringSubset(str.substr(1), ans, v);
}

int main(){
    string str;
    cout << "Enter the string: ";
    getline(cin, str);
    vector<string>v;
    stringSubset(str, "", v);
    for (int i = 0; i<v.size(); i++){
        cout << v[i] << endl;
    }
}