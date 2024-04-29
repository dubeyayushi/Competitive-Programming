#include<iostream>
using namespace std;

void CheckSorting(int array[], int size){
    bool flag = true;
    for (int i = 0; i<size; i++){
        for (int j = i+1; j<size; j++){
            if (array[i]>array[j]){
                flag = false;
                break;
            }
        }
    }
    if (flag){
        cout << "array sorted" << endl;
    }
    else{
        cout << "array not sorted" << endl;
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

    CheckSorting(array, n);
    
}