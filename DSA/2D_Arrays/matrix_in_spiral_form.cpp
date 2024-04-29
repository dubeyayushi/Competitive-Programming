#include<iostream>
using namespace std;
 
int main(){
    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    int nums[m][n];
    
    cout << "Enter the elements: "<< endl;
    for (int i= 0; i<m; i++){
        for (int j = 0; j<n; j++){
            cin >> nums[i][j];
        }
    }

    int maxr = m-1, minr = 0, maxc = n-1, minc = 0;

    while(minr<=maxr && minc<=maxc){
        for (int i = minc; i<=maxc; i++){
            cout << nums[minr][i] << " ";
        }
        minr++;
        if (minr>maxr || minc>maxc){
            break;
        }
        for (int i = minr; i<=maxr; i++){
            cout << nums[i][maxc] << " ";
        }
        maxc--;
        if (minr>maxr || minc>maxc){
            break;
        }
        for(int i = maxc; i>=minc; i--){
            cout << nums[maxr][i] << " ";
        }
        maxr--;
        if (minr>maxr || minc>maxc){
            break;
        }
        for (int i = maxr; i>=minr; i--){
            cout << nums[i][minc] << " ";
        }
        minc++;
    }
}