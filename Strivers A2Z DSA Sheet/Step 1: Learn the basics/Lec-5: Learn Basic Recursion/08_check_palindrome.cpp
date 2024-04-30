// https://www.naukri.com/code360/problems/check-palindrome-recursive_624386?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

bool helper(string& str, int i, int j){
    if (i>j) return true;
    if (str[i]!=str[j]) return false;
    helper(str, i+1, j-1);
}

bool isPalindrome(string& str) {
    // Write your code here.
    int n = str.length();
    return helper(str, 0, n-1);
}
