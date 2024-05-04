// https://www.naukri.com/code360/problems/linear-search_6922070?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

int linearSearch(int n, int num, vector<int> &arr)
{
    // Write your code here.
    for (int i = 0; i<n; i++){
        if (arr[i]==num) return i;
    }
    return -1;
}
