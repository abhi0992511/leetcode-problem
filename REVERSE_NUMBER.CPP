#include <bits/stdc++.h>
using namespace std;
int palidorme(int n)
{
	int s=0;
	while(n>0)
	{
		int x=n%10;
		n=n/10;
		s=s*10+x;
	}
	return s;
}
int main()
{
	int n;
	cin>>n;
	cout<<palidorme(n);
}