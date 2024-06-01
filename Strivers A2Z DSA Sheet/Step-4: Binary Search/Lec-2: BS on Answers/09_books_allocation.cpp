// https://www.naukri.com/code360/problems/allocate-books_1090540?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries&nps=true&leftPanelTabValue=PROBLEM

bool check(int pages, vector<int>& arr, int m){
    int totalPages = 0;
    int studentCount = 1;
    for (int i = 0; i<arr.size(); i++){
        if (totalPages+arr[i] <= pages){
            totalPages += arr[i];
        }
        else{
            studentCount++;
            totalPages = arr[i];
        }
        if (studentCount>m) return false;
    }
    return true;
}

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if (m>n) return -1;
    int maxPages = INT_MIN;
    int sum = 0;
    for (int i = 0; i<arr.size(); i++){
        maxPages = max(maxPages, arr[i]);
        sum += arr[i];
    }
    int start = maxPages;
    int end = sum;
    while(start<=end){
        int mid = start + (end-start)/2;
        if (check(mid, arr, m)){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return start;
}