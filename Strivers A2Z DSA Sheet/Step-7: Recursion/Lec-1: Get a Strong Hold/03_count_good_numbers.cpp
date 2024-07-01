// https://leetcode.com/problems/count-good-numbers/description/

#define mod 1000000007
class Solution {
public:
    long long helper(long long num, long long x, long long ans){
        if (num==0){
            return ans%mod;
        }
        if (num%2==1){
            ans = (ans * x)%mod;
            num = num-1;
        }
        else{
            x = (x * x)%mod;
            num = num/2;
        }
        return helper(num, x, ans);
    }
    int countGoodNumbers(long long n) {
        long long numOdd = n/2;
        long long numEven = n - numOdd;
        long long ans = (helper(numOdd, 4, 1) * helper(numEven, 5, 1))%mod;
        return ans;
    }
};