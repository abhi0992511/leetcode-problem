#include <bits/stdc++.h>
using namespace std;
int lss(int n,int *a)
{
	int *dp=new int[n+1];
	dp[0]=1;
	for(int i=1;i<n+1;i++)
	{
		if (a[i]>a[i-1])
		{
			dp[i]=dp[i-1]+1;
		}
		else
			dp[i]=dp[i-1];
	}
	return dp[n]-1;
}
int lis(int n,int*a)
{
	int *dp=new int[n];
	dp[0]=1;
	for (int i = 1; i < n; ++i)
	{
		
		for(int j=i-1;j>=0;j--)
		{
			dp[i]=1;
			if (a[j]>a[i])
			{
			continue;
			}
			int ans=dp[j]+1;
			if (ans>dp[i-1])
			{
				dp[i]=ans;
			}
		}
	}
	int best=0;
	for (int i = 0; i < n; ++i)
	{
		if (best<dp[i])
		{
			best=dp[i];
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
	cout<<lss(n,a)<<endl;
	cout<<lis(n,a);
}