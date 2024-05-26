// https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=ceil-the-floor

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    int floorVal = INT_MIN;
    int ceilVal = INT_MAX;
    for (int i = 0; i<n; i++){
        if (arr[i]<=x){
            floorVal = max(arr[i], floorVal);
        }
        if (arr[i]>=x){
            ceilVal = min(arr[i], ceilVal);
        }
    }
    if (floorVal==INT_MIN) floorVal = -1;
    if (ceilVal==INT_MAX) ceilVal = -1;
    return {floorVal, ceilVal};
}