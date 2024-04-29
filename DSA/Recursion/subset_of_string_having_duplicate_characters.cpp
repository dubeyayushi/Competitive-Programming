#include<iostream>
#include<vector>
#include<string>
using namespace std;
 
void duplicateStringSubset(string original, string ans, vector<string>&v, bool flag){
    if (original==""){
        v.push_back(ans);
        return;
    }

    char ch = original[0];
    if (original.length()==1){
        if (flag==true){
            duplicateStringSubset(original.substr(1), ans+ch, v, true);
        }
        duplicateStringSubset(original.substr(1), ans, v, true);
        return;
    }
    char dh = original[1];
    if (ch==dh){
        if (flag==true){
            duplicateStringSubset(original.substr(1), ans+ch, v, true);
        }
        duplicateStringSubset(original.substr(1), ans, v, false);
    }
    else{
        if (flag==true){
            duplicateStringSubset(original.substr(1), ans+ch, v, true);
        }
        duplicateStringSubset(original.substr(1), ans, v, true);
    }
}

int main(){
    string str;
    cout << "Enter the string: ";
    getline (cin, str);
    vector<string>v;
    duplicateStringSubset(str, "", v, true);

    for (int i = 0; i<v.size(); i++){
        cout<< v[i] << endl;
    }
}