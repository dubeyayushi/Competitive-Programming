// https://www.naukri.com/code360/problems/n-to-1-without-loop_8357243?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

void helper(int x, vector<int>&ans){
    if (x==1){
        ans.push_back(x);
        return;
    }
    ans.push_back(x);
    helper(x-1, ans);
}

vector<int> printNos(int x) {
    // Write Your Code Here
    vector<int>ans;
    helper(x, ans);
    return ans;
}