// https://www.naukri.com/code360/problems/traffic_6682625?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

int traffic(int n, int m, vector<int> vehicle) {
	// Write your code here.
	int l = 0;
	int r = 0;
	int zero = 0;
	int ans = 0;

	while(r<n){
		if (vehicle[r]==0){
			zero++;
			while(zero>m){
				if (vehicle[l]==0){
					zero--;
				}
				l++;
			}
		}
		ans = max(ans, r-l+1);
		r++;
	}
	return ans;
}
