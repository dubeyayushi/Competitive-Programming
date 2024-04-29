#include<iostream>
using namespace std;

void merge(int input[], int si, int ei, int mid){
    int i, j, k;
    int n1 = mid - si + 1;
    int n2 = ei - mid;

    int a[n1], b[n2];

    for (int i = 0; i<n1; i++){
        a[i] = input[si+i];
    }
    for (int j = 0; j<n2; j++){
        b[j] = input[mid+1+j];
    }

    i = 0;
    j = 0; 
    k = si;

    while(i < n1 && j < n2){
        if(a[i]<=b[j]){
            input[k] = a[i];
            i++;
        }
        else{
            input[k] = b[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        input[k] = a[i];
        i++;
        k++;
    }


    while(j<n2){
        input[k] = b[j];
        j++;
        k++;
    }

}

void mergeSorthelper(int input[], int si, int ei){
    if (si>=ei){
        return;
    }

    int mid = (ei+si)/2;

    mergeSorthelper(input, si, mid);
    mergeSorthelper(input, mid+1, ei);
    merge(input, si, ei, mid);
    
}

void mergeSort(int input[], int size){
    mergeSorthelper(input, 0, size-1);
}

int main(){
    int input[5] = {9,4,6,4,2};
    mergeSort(input, 5);
    for (int i= 0; i<5; i++){
        cout << input[i] << " ";
    }
}




