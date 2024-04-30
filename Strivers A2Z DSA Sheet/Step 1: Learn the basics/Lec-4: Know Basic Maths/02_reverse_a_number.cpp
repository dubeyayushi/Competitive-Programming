// https://www.naukri.com/code360/problems/reverse-bits_2181102?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

long reverseBits(long n) {
    long ans = 0;
    for (int i = 0; i < 32; i++) {
        ans = (ans << 1) | (n & 1);
        n >>= 1;
    }
    return ans;
}
