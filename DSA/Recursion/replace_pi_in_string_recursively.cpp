#include <bits/stdc++.h>
using namespace std;

void replacePihelper(char input[], int start) {
    if (input[start]=='\0' || input[start+1]=='\0'){
        return;
    }

    replacePihelper(input, start+1);

    if (input[start]=='p' && input[start+1]=='i'){
        for (int i = strlen(input); i >= start + 2; i--) {
            input[i + 2] = input[i];
        }

        input[start] = '3';
        input[start+1] = '.';
        input[start+2] = '1';
        input[start+3] = '4';
    }

}

void replacePi(char input[]){
    replacePihelper(input, 0);
}

int main(){
    char a[] = "xpipix";
    replacePi(a);
    cout << a << endl;

}
