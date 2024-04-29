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
            end = nums[mid-1];
            break;
        }
        else if (nums[mid]>val){
            end = mid - 1;
            continue;
        }
        else{
            start = mid+1;
            continue;
        }
    }
    cout << "the lower bound of " << val << " is: " << nums[end];
}