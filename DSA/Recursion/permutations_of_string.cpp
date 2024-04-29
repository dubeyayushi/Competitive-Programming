#include<iostream>
#include<vector>
#include<string>
using namespace std;

void permutationString(string str, string ans, vector<string>&v){
    if (str==""){
        v.push_back(ans);
        return;
    }
    for (int i = 0; i<str.length(); i++){
        char ch = str[i];
        string left = str.substr(0, i);
        string right = str.substr(i+1);
        permutationString(left+right, ans+ch, v);
    }
}
 
int main(){
    string str;
    cout << "Enter the string: ";
    cin >> str;

    vector<string>v;
    permutationString(str, "", v);

    for (int i = 0; i<v.size(); i++){
        cout << v[i] << endl;
    }
}