#include<iostream>
using namespace std;

void ReversePartofArray(int array[], int size, int si, int ei){
    for (int i = si; i<ei; i++){
        int temp = array[i];
        array[i] = array[ei-1];
        array[ei-1] = temp;
        ei--;
    }
}

int main(){
    cout << "Enter number of elements in array:";
    int n;
    cin >> n;

    int array[n];
    cout << "Enter elements:";
    for (int i = 0; i<n; i++){
        cin >> array[i];
    }
    
    int steps;
    cout << "Enter the steps:";
    cin >> steps;
    if(steps>n){
        steps = steps%n;
    }
    ReversePartofArray(array, n, 0, n-steps);
    ReversePartofArray(array, n, n-steps, n);
    ReversePartofArray(array, n, 0, n);

    for(int i = 0; i<n; i++){
        cout << array[i] << endl;
    }
}