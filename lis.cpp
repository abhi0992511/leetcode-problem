#include<bits/stdc++.h>
using namespace std;
int lis(int *a,int n)
{
	int *ans=new int[n];
	ans[0]=1;
	for (int i = 1; i < n; ++i)
	{
		ans[i]=1;
		for (int j = 0; j <i ; j++)
		{
	          if (a[j]>a[i])
	          {
	          	continue;
	          }
	          int possible=ans[j]+1;
	          if (possible>ans[i])
	          {
	          	ans[i]=possible;
	          }
		}
	}
	int best=0;
	for (int i = 0; i < n; ++i)
	{
		if (best<ans[i])
		{
			best=ans[i];
		}
	}
	return best;
}
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int ans=lis(a,n);
	cout<<ans;
}