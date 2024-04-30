// https://www.naukri.com/code360/problems/nth-fibonacci-number_74156?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<bits/stdc++.h>
using namespace std;

int main()
{
        /*
        *  Write your code here. 
         *  Read input as specified in the question.
         *  Print output as specified in the question.
        */
        int n;
        cin >> n;
        int a = 0;
        int b = 1;
        int ans = a + b;
        for (int i = 3; i<=n; i++){
                a = b;
                b = ans;
                ans = a + b;
        }
        cout << ans << endl;
}