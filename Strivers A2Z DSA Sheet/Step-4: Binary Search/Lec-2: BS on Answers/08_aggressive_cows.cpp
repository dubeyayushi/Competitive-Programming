// https://www.spoj.com/problems/AGGRCOW/

#include<iostream>
#include<vector>
using namespace std;
 
int check(int dist, vector<int>& stallPos, int c){      // n
    int countCows = 1;
    int last = stallPos[0];
    for (int i = 1; i<stallPos.size(); i++){
        if (stallPos[i]-last>=dist){
            countCows++;
            last = stallPos[i];
        }
        if (countCows>=c) return true;
    }
    return false;
}

int aggCows(vector<int>& stallPos, int c){
    sort(stallPos.begin(), stallPos.end());    //nlogn
    int n = stallPos.size();
    int start = 1;
    int end = stallPos[n-1] - stallPos[0];
    while(start<=end){      // logn
        int mid = start + (end-start)/2;
        if (check(mid, stallPos, c)){   
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return end;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;
        vector<int>stallPos(n);
        for (int i = 0; i<n; i++){
            cin >> stallPos[i];
        }
        cout << aggCows(stallPos, c) << endl;   // TC: O(nlogn)
    }
    return 0;
}