#include<iostream>
#include<climits>
using namespace std;

void LargestThreeElements(int array[], int size){
    int first = array[size-1], second = array[size-2], third = array[size-3];

    for (int i = 0; i<size; i++){
        if (array[i]>first){
            first = array[i];
        }
        else if (array[i]<first && array[i]>second){
            second = array[i];
        }
        else if (array[i]<first && array[i]<second && array[i]>third){
            third = array[i];
        }
    }

    cout << first << " " << second << " " << third;
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

    LargestThreeElements(array, n);
}