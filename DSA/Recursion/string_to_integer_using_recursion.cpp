#include<iostream>
using namespace std;

int stringToNumberhelper(char input[], int start, int size) {
    if (size == 0){
        return 0;
    }

    stringToNumberhelper(input, start+1, size-1);

    int sum = 0;
    for (int i = 0; i<size; i++){
        sum = (sum*10) + (input[i] - '0');
    }
    return sum;
}    

int stringToNumber(char input[]) {
    int size = 0;
    for (int i = 0; input[i]; i++){
        size++;
    }
    return stringToNumberhelper(input, 0, size);
}

int main(){
    char a[] = "1234";
    cout << stringToNumber(a) << endl;
}
