#include <bits/stdc++.h>
using namespace std;
//RECURSIVE:
int lote(int s,int *a,int n)
{
	if (s>=n)
	{
		return 0;

	}
	return max(a[s]+lote(s+2,a,n),lote(s+1,a,n));
}
//MEMOISATION:
int lote(int s,int *a,int n,int *dp)
{
	if (s>=n)
	{
		return 0;
	}
	if (dp[s]!=-1)
	{
		return dp[s];
	}
	return dp[s]=max(a[s]+lote(s+2,a,n,dp),lote(s+1,a,n,dp));
}
//DP:
int lote(int *a,int n)
{
	int *dp=new int[n];
	dp[0]=a[0];
	dp[1]=max(a[0],a[1]);
	for (int i = 2; i <n; ++i)
	{
	    dp[i]=max(a[i]+dp[i-2],dp[i-1]);
	}
	return dp[n-1];
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
	int *dp=new int[n];
	for (int i = 0; i < n; ++i)
	{
		dp[i]=-1;
	}
	cout<<lote(0,a,n,dp)<<endl;
	cout<<lote(0,a,n)<<endl;
	cout<<lote(a,n);
}