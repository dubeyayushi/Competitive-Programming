// https://www.naukri.com/code360/problems/print-1-to-n_628290?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

void helper(vector<int>&v, int i, int x){
    if (i==x){
        v.push_back(i);
        return;
    }
    v.push_back(i);
    helper(v, i+1, x);
}
vector<int> printNos(int x) {
    // Write Your Code Here
    vector<int>v;
    helper(v, 1, x);
    return v;
}