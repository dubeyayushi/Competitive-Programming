#include<iostream>
using namespace std;

int main() {
	// Write your code here
	char ch;
	cin >> ch;
	int val = ch;
	if (val>=65 && val<=90){
		cout << 1 << endl;
	}
	else if (val>=97 && val<=122){
		cout << 0 << endl;
	}
	else{
		cout << -1 << endl;
	}
}
