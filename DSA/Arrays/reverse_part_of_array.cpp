#include<iostream>
using namespace std;

void ReversePartofArray(int array[], int size, int reverse_index){
    for (int i = 0; i<=reverse_index; i++){
        int temp = array[i];
        array[i] = array[reverse_index];
        array[reverse_index] = temp;
        reverse_index--;
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
    
    int reverse_index;
    cout << "Enter the index upto which array is to be reversed:";
    cin >> reverse_index;
    ReversePartofArray(array, n, reverse_index);

    for(int i = 0; i<n; i++){
        cout << array[i] << endl;
    }
}