#include<iostream>
using namespace std;
 
int main(){
    int n;
    cout << "Enter order of square matrix: ";
    cin >> n;

    int nums[n][n];
    
    int maxr = n-1, minr = 0, maxc = n-1, minc = 0, count = 1;

    while(minr<=maxr && minc<=maxc){
        for (int i = minc; i<=maxc; i++){
            nums[minr][i] = count;
            count++;
        }
        minr++;
        if (minr>maxr || minc>maxc){
            break;
        }
        for (int i = minr; i<=maxr; i++){
            nums[i][maxc] = count;
            count++;
        }
        maxc--;
        if (minr>maxr || minc>maxc){
            break;
        }
        for(int i = maxc; i>=minc; i--){
            nums[maxr][i] = count;
            count++;
        }
        maxr--;
        if (minr>maxr || minc>maxc){
            break;
        }
        for (int i = maxr; i>=minr; i--){
            nums[i][minc] = count;
            count++;
        }
        minc++;
    }

    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}