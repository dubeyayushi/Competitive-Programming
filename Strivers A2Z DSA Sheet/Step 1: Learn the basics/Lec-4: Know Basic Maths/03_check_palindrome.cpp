// https://www.naukri.com/code360/problems/palindrome-number_624662?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

bool palindrome(int n)
{
    // Write your code here
    int rev = 0;
    int num = n;
    while(num){
        int digit = num%10;
        num /= 10;
        rev = rev*10 + digit;
    }
    if (rev==n) return true;
    return false;
}