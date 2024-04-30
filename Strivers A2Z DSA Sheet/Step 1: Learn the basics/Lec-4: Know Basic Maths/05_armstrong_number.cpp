// https://www.naukri.com/code360/problems/check-armstrong_589?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

bool checkArmstrong(int n){
	//Write your code here
	int num = n;
	int len = 0;
	while(num){
		num/=10;
		len++;
	}
	int ans = 0;
	num = n;
	while(n){
		int digit = n%10;
		ans += pow(digit, len);
		n /= 10;
	}
	return ans == num;
}

