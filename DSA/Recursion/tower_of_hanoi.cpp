#include<iostream>
using namespace std;
 
void towerOfHanoi(int n, char source, char helper, char destination){
    if (n==0){
        return;
    }
    towerOfHanoi(n-1, source, destination, helper);
    cout << source << "-->" << destination << endl;
    towerOfHanoi(n-1, helper, source, destination);
}

int main(){
    int n;
    cout << "Enter the number of rods: ";
    cin >> n;
    towerOfHanoi(n, 'A', 'B', 'C');
}

