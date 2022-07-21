#include <bits/stdc++.h>
using namespace std;
//USING_RECURSION:
int amount(int s,int n,int *a)
{
	if (s>=n)
	{
		return 0;
	}
	int ans=max(amount(s+2,n,a)+a[s],amount(s+1,n,a));
	return ans;
}
//USING_MEMOISATION:
int amount2(int s,int n,int *a,int *dp)
{
if (s>=n)
	{
		return 0;
	}
	if (dp[s]!=-1)
	{
		return dp[s];
	}
	int ans=max(amount2(s+2,n,a,dp)+a[s],amount2(s+1,n,a,dp));
	dp[s]=ans;
	return ans;	
}
// USING_DP:
int amount3(int n,int *a)
{
	int *dp=new int [n];
	dp[0]=a[0];
	dp[1]=max(a[0],a[1]);
	for(int i=2;i<n;i++)
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
	int *dp=new int [n];
	for (int i = 0; i < n; ++i)
	{
		dp[i]=-1;
	}
	cout<<amount2(0,n,a,dp)<<endl;
	cout<<amount3(n,a);
}