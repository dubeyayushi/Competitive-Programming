#include<iostream>
#include<vector>
using namespace std;
 
int main(){
    int n; 
    cout << "Enter the size of the array: ";
    cin >> n; 
    vector <int> nums(n);
    cout << "Enter the elements:" << endl;
    for (int i = 0; i<n; i++){
        cin >> nums[i];
    }
    int val;
    cout << "Enter the element: ";
    cin >> val;

    int start = 0; 
    int end = n-1;
    while(start<=end){
        int mid = (start+end)/2;
        if (nums[mid]==val){
            if (nums[mid-1]==val){
                end = mid-1;
                continue;
            }
            else{
                end = mid;
                break;
            }
        }
        else if(nums[mid]<val){
            start = mid+1;
        }
        else{
            end = mid-1;

        }
    }
    cout << "The first occurrence of " << val << " is at:  " << end;
}