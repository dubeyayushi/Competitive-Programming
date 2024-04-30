// https://www.naukri.com/code360/problems/sum-of-even-odd_624650?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int n;
	cin >> n;
	int evenSum = 0;
	int oddSum = 0;
	while(n){
		int digit = n%10;
		n = n/10;
		if (digit%2==0) evenSum += digit;
		else oddSum += digit;
	}
	cout << evenSum << " " << oddSum << endl;
}
