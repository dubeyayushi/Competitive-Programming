#include<iostream>
#include<iostream>
using namespace std;
 
int main(){
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);

    int count = 0;

    for (int i = 0; i<str.size(); i++){
        if (str.size() == 1){
            break;
        }
        if (i==0){
            if (str[i]!=str[i+1]){
                count++;
                continue;
            }
        }

        if (i==str.size()-1){
            if (str[i] != str[i-1]){
                count++;
                continue;
            }
        }
        if ((str[i] != str[i-1]) && (str[i]!= str[i+1])){
            count++;
        }
    }

    cout << "The number of times neighbours are different in given string is: " << count << endl;
}