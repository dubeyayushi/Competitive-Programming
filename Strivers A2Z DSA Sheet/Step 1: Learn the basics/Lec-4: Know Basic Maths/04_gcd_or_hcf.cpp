// https://www.naukri.com/code360/problems/hcf-and-lcm_840448?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

int gcd(int a, int b){
    if (b==0){
        return a;
    }
    return gcd(b, a%b);
}

int calcGCD(int n, int m){
    // Write your code here.
    return gcd(n, m);
}