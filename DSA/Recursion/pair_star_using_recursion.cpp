#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void pairStarhelper(char input[], int start) {
    if (input[start] == '\0') {
        return;
    }
    pairStarhelper(input, start + 1);

    if (input[start] == input[start + 1]) {
        int len = strlen(input);
        input[len + 1] = '\0';
        for (int i = len - 1; i > start; i--) {
            input[i + 1] = input[i];
        }
        input[start + 1] = '*';
    }
}

void pairStar(char input[]) {
    pairStarhelper(input, 0);
}


int main(){
    char a[] = "hello";
    pairStar(a);
    cout << a << endl;
}

