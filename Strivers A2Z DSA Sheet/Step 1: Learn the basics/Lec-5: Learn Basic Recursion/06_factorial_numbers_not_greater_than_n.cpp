// https://www.naukri.com/code360/problems/factorial-numbers-not-greater-than-n_8365435?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

long long factorial(long long i){
    if (i==0 || i==1) return 1;
    return i*factorial(i-1);
}

vector<long long> factorialNumbers(long long n) {
    // Write Your Code Here
    vector<long long> ans;
    for (long long i = 1; i<=n; i++){
        long long fact = factorial(i);
        if (fact>n) break;
        ans.push_back(fact);
    }
    return ans;
}