#include<iostream>
using namespace std;

int partition(int input[], int si, int ei){
    int count_smaller_elements = 0;
    for (int i = si+1; i<=ei; i++){
        if(input[i] <= input[si]){
            count_smaller_elements++;
        }
    }
    
    int pivot_index = si + count_smaller_elements;
    int temp = input[pivot_index];
    input[pivot_index] = input[si];
    input[si] = temp;

    int i = si;
    int j = ei;

    while(i<pivot_index && j>pivot_index){
        if (input[i]<=input[pivot_index]){
            i++;
        }
        else if(input[j]>input[pivot_index]){
            j--;
        }
        else{
            int num = input[i];
            input[i] = input[j];
            input[j] = num;
        }
    }
    return pivot_index;
}

void quickSorthelper(int input[], int si, int ei) {
    if (si>=ei){
        return;
    }

    int pivot_index = partition(input, si, ei);

    quickSorthelper(input, si, pivot_index-1);
    quickSorthelper(input, pivot_index+1, ei);
}

void quickSort(int input[], int size) {
    quickSorthelper(input, 0, size-1);
}

int main(){
    int input[6] = {1, 5, 9, 7, 2, 8};
    quickSort(input, 6); 
    for (int i = 0; i<6; i++){
        cout << input[i] << " ";
    }
}