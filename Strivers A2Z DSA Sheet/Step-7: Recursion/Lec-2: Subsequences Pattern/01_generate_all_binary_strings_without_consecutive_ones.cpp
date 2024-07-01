#include <bits/stdc++.h>
using namespace std;

void All_Binary_Strings(string str,int num)
{
	int len=str.length();
	if(len==num)
	{
		cout<<str<<" ";
		return;
	}
	else if(str[len-1]=='1')
		All_Binary_Strings(str+'0',num);
	else
	{
		All_Binary_Strings(str+'0',num);
		All_Binary_Strings(str+'1',num);
	}
}

void print(int& num)
{
	string word;
	word.push_back('0');
	All_Binary_Strings(word,num);
	word[0]='1';
	All_Binary_Strings(word,num);
}

//driver's code
int main()
{
	int n=4;
	print(n);
	return 0;
}
