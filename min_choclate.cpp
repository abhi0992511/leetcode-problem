#include <bits/stdc++.h>
using namespace std;
int min_choco(int *a,int n,int i)
{
	if (i>=n)
	{
		return 0;
	}
	if (a[i]>=a[i+1])
	{
		return 2+min_choco(a,n,i+1);
	}
	else
		return min_choco(a,n,i+1)+1;
}
int main()
{
	int n;
	cin>>n;
	int *a=new int [n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cout<<min_choco(a,n,0);
}