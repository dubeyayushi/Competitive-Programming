// https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	int start = 0;
	int end = n-1;
	int floorVal = -1;
	int ceilVal = -1;
	while(start<=end){
		int mid = start + (end-start)/2;
		if (a[mid]>=x){
			ceilVal = a[mid];
			end = mid-1;
		}
		if (a[mid]<=x){
			floorVal = a[mid];
			start = mid+1;
		}
	}
	return {floorVal, ceilVal};
}