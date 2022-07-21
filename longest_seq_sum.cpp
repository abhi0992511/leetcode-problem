#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int inc=a[0];
	int ex=0;
	for (int i = 1; i < n; ++i)
	{
		int ninc=ex+a[i];
		int nex=max(inc,ex);
		inc=ninc;
		ex=nex;
	}
	cout<<max(inc,ex);
}