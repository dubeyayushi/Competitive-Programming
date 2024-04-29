#include<iostream>
#include<string>
using namespace std;
 
void removeChar(string ans, string original){
    if (original==""){
        cout << ans;
        return;
    }
    if (original[0]=='a'){
        removeChar(ans, original.substr(1));
    }
    else{
        removeChar(ans+original[0], original.substr(1));
    }
}

int main(){
    string str;
    cout << "Enter the string: ";
    getline(cin, str);
    removeChar("", str);
}