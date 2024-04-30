// https://www.naukri.com/code360/problems/k-most-occurrent-numbers_625382?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

vector<int> getFrequencies(vector<int>& v) {
    // Write Your Code Here
    map<int, int>mp;
    for (int i = 0; i<v.size(); i++){   //O(nlogn)
        mp[v[i]]++;
    }
    vector<int>ans(2);
    int minele = INT_MAX;
    int maxele = INT_MIN;
    for (auto ele : mp){    //O(logn)
        if (ele.second>maxele){
            ans[0] = ele.first;
            maxele = ele.second;
        }
        if (ele.second<minele){
            ans[1] = ele.first;
            minele = ele.second;
        }
    }
    return ans;
}