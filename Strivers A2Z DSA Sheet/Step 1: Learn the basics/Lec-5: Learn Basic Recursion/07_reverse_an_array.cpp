// https://www.naukri.com/code360/problems/reverse-an-array_8365444?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

vector<int> reverseArray(int n, vector<int> &nums)
{
    // Write your code here.
    for (int i = 0; i<n/2; i++){
        swap(nums[i], nums[n-i-1]);
    }
    return nums;
}
