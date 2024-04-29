#include<iostream>
using namespace std;

char helper(char input[], int start, int end);
bool checkPalindrome(char input[]) {
    int size = 0;
    for(int i = 0; input[i]; i++){
        size++;
    }
    return helper(input, 0, size-1);
}

char helper(char input[], int start, int end){
    if (end-start==1 || end-start==0){
        return true;
    }

    if(input[start]!=input[end]){
        return false;
    }
    else{
        return helper(input, start+1, end-1);
    }
}

int main(){
    char a[]= "racecar";
    cout << checkPalindrome(a);
}