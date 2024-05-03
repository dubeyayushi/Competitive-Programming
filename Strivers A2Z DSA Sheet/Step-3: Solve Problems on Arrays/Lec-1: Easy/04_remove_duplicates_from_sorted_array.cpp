// https://www.naukri.com/code360/problems/remove-duplicates-from-sorted-array_1102307?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int ele = arr[0];
	int ans = 1;
	for (int i = 1; i<n; i++){
		if (arr[i]==ele) continue;
		else{
			ele = arr[i];
			ans++;
		}
	}
	return ans;
}