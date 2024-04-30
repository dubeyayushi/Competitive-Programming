// https://www.naukri.com/code360/problems/-print-n-times_8380707?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

void helper(int i, int n, vector<string>&ans){
	if (i==n){
		ans.push_back("Coding Ninjas");
		return;
	}
	ans.push_back("Coding Ninjas");
	helper(i+1, n, ans);
}

vector<string> printNTimes(int n) {
	// Write your code here.
	vector<string>ans;
	helper(1, n, ans);
	return ans;
}