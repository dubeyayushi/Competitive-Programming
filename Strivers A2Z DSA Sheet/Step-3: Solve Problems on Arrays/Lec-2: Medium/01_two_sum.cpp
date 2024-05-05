// https://www.naukri.com/code360/problems/reading_6845742?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

string read(int n, vector<int> book, int target)
{
    // Write your code here.
    sort(book.begin(), book.end());
    int left = 0;
    int right = n-1;
    while(left<right){
        int sum = book[left] + book[right];
        if (sum==target) return "YES";
        else if (sum<target) left++;
        else right--;
    }
    return "NO";
}
