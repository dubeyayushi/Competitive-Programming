#include<iostream>
#include<string>
using namespace std;

int subs(string s, string output[]){
    if (s.empty()){
        output[0] = "";
        return 1;
    }

    string smallstring = s.substr(1);
    int smalloutputsize = subs(smallstring, output);
    for (int i = 0; i<smalloutputsize; i++){
        output[smalloutputsize+i] = s[0] + output[i]; 
    }
    return 2*smalloutputsize;
}

int keypad(int num, string output[]){
    if (num == 0 || num == 1){
        output[0] = "";
        return 1;
    }

    int smalloutputsize = keypad(num%10, output);

    string strings[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    int digit = num%10;
    string s = strings[digit-2];
    return subs(s, output);
}

int main(){
    int input;
    cin >> input;
    string* output = new string[10000];
    int count = keypad(input, output);
    for (int i = 0; i<count; i++){
        cout << output[i] << endl;
    }
}