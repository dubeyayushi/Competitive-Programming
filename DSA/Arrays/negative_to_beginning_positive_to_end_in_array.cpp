#include<iostream>
using namespace std;

void NegativeToBeginningPositiveToEnd(int array[], int size){
    int i = 0, j = size-1;
    while (i<j){
        if (array[i]>0 && array[j]<0){
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
        else if(array[i]<0){
            i++;
        }
        else if(array[j]>0){
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

    NegativeToBeginningPositiveToEnd(array, n);

    for (int i = 0; i<n; i++){
        cout << array[i] << " ";
    }
    
}