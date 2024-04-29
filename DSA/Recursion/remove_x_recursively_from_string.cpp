#include<iostream>
#include<cstring>
using namespace std;

void removeXhelper(char input[], int start) {
    if (input[start] == '\0'){
        return;
    }
    
    removeXhelper(input, start+1);

    if(input[start]=='x'){
        for (int i = start; input[i]; i++){
            input[i] = input[i+1];
        }
    }
}

void removeX(char input[]){
    removeXhelper(input, 0);
}

int main (){
    char input[] = "norx";
    removeX(input);
    cout << input << endl;
}