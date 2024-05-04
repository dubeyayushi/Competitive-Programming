// https://www.naukri.com/code360/problems/sorted-array_6613259?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Write your code here
    int i = 0;
    int j = 0;
    int n = a.size();
    int m = b.size();
    vector<int>ans;
    int count = 0;

    while(i<n && j<m){
        int ele;
        if (a[i]<b[j]){
            ele = a[i];
            i++;
        }
        else if (a[i]>b[j]){
            ele = b[j];
            j++;
        }
        else{
            ele = a[i];
            i++;
            j++;
        }
        if (count!=0 && ans[count-1]==ele) continue;
        ans.push_back(ele);
        count++;
    }   
    while(i<n){
        int ele = a[i];
        if (ans[count-1]!=ele){
            ans.push_back(ele);
            count++;
        }
        i++;
    }
    while(j<m){
        int ele = b[j];
        if (ans[count-1]!=ele){
            ans.push_back(ele);
            count++;
        }
        j++;
    }
    return ans;
}