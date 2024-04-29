#include<iostream>
using namespace std;

void SortZeroesAndOnes(int array[], int size){
    int i = 0, j = size-1;
    while(i<j){
        if (array[i] == 1 && array[j] == 0){
            array[i] = 0;
            array[j] = 1;
            i++;
            j--;
        }
        if (array[i] == 0){
            i++;
        }
        if (array[j] == 1){
            j--;
        }
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

    SortZeroesAndOnes(array, n);

    for (int i = 0; i<n; i++){
        cout << array[i] << endl;
    }
    
}