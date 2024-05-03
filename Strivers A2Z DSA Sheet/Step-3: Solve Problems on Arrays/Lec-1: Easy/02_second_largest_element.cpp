// https://www.naukri.com/code360/problems/ninja-and-the-second-order-elements_6581960?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse&leftPanelTabValue=PROBLEM

vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Write your code here.
    int maxele = INT_MIN;
    int minele = INT_MAX;
    vector<int> ans = {INT_MIN, INT_MAX};
    for (int i = 0; i<a.size(); i++){
        if (a[i]>maxele) maxele = a[i];
        if (a[i]<minele) minele = a[i];
    }
    for (int i = 0; i<a.size(); i++){
        if (a[i]>ans[0] && a[i]<maxele) ans[0] = a[i];
        if (a[i]<ans[1] && a[i]>minele) ans[1] = a[i];
    }
    return ans;
}
