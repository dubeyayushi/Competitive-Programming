// https://www.naukri.com/code360/problems/ninja-and-the-zero-s_6581958?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

vector<int> moveZeros(int n, vector<int> a) {
    // Write your code here.
    int zeroIdx = -1;
    for (int i = 0; i<n; i++){
        if (a[i]==0){
            zeroIdx = i;
            break;
        }
    }
    if (zeroIdx==-1) return a;
    for (int i = zeroIdx+1; i<n; i++){
        if (a[i]!=0) {
            swap(a[i], a[zeroIdx]);
            zeroIdx++;
        }
    }
    return a;
}
