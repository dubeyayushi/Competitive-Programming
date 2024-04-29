#include<iostream>
using namespace std;
 
void goodMorning(int n){
    if (n==0){
        return;
    }
    cout << "Good Morning" << endl;
    goodMorning(n-1);
}

int main(){
    int n;
    cout<< "Enter the number of times good morning has to be printed: ";
    cin >> n;

    goodMorning(n);
}