#include<iostream>
#include<vector>
#include<string>
using namespace std;
 
void stringSubsequence(string original, string ans, vector<string>&v, int k){
    if (original==""){
        if (ans.length()==3){
            v.push_back(ans);
        }
        return;
    }
    stringSubsequence(original.substr(1), ans+original[0], v, k);
    stringSubsequence(original.substr(1), ans, v, k);
}

int main(){
    string str;
    cout << "Enter the string: ";
    getline(cin, str);

    int k;
    cout << "Enter the length of the subsequence: ";
    cin >> k;
    vector<string>v;
    stringSubsequence(str, "", v, k);
    for (int i = 0; i<v.size(); i++){
        cout << v[i] << endl;
    }
}