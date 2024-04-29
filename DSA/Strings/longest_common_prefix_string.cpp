#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

string prefix(vector<string>v){
    int length = v.size();
    string str = "";

    for (int i = 0; i<v[0].size(); i++){
        if (v[0][i]==v[length-1][i]){
            str = str+v[0][i];
        }
        else{
            return str;
        }
    }
    return str;
}

int main(){
    string s;
    getline(cin, s);
    stringstream ss(s);
    string temp;
    vector<string>v;
    while(ss>>temp){
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    cout << prefix(v) << endl;
}