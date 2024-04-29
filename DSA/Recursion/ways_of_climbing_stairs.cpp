#include<iostream>
using namespace std;
 
int countSteps(int n){
    if (n==0){
        return 1;
    }
    else if (n<0){
        return 0;
    }
    else{
        return countSteps(n-3) + countSteps(n-2) + countSteps(n-1);
    }

}

int main(){
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;
    cout << "The number of ways are: " << countSteps(n);
}