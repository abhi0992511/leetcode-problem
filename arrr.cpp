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
	int x=n+1;
	for (int i = 0; i < n; ++i)
	{
		if (n==1)
		{
			cout<<"1";
		}
		x=x+a[i];
		if(x==1)
		{
			 cout<<n+1;
		}

	}
}