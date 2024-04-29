#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int minProduct(vector<int>&arr){
    int ans = INT_MAX;
    int cn = 0; //number of negatives in array
    int cz = 0; //number of zeroes in array
    int cp = 0; //number of positives in array
    int prodPos = 1;
    int prodNeg = 1;
    int largestNeg = INT_MIN;
    for (int i = 0; i<arr.size(); i++){
        if (arr[i]<0){
            cn++;
            prodNeg *= arr[i];
            largestNeg = max(arr[i], largestNeg);
        }
        else if (arr[i]==0){
            cz++;
        }
        else{
            cp++;
            prodPos *= arr[i];
        }
    }
    if (cn == 0){
        if (cz>0){
            return 0;
        }
        else{
            auto it = min_element(arr.begin(), arr.end());
            return *it;
        }
    }
    else{   //there are negatives in the array
        if (cn%2==0){   //even number of negatives
            prodNeg /= largestNeg;
            return prodPos*prodNeg;
        }
        else{   //odd number of negatives
            return prodPos*prodNeg;
        }
    }
    
}    

int main(){
    vector<int>arr{1, 2, 3};
    cout << minProduct(arr) << endl;
    return 0;
}