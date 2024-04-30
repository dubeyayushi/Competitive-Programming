// https://www.naukri.com/code360/problems/count-digits_8416387?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

int countDigits(int n){
	// Write your code here.	
	int num = n;
	int ans = 0;
	while(num){
		int a = num%10;
		num /= 10;
		if (a==0){
			continue;
		}
		if (n%a==0){
			ans++;
		}
	}
	return ans;
}