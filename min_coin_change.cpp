#include <bits/stdc++.h>
using namespace std;
//RECURSIVE:
int min_coin(int *a,int n,int coin)
{
	if (n==0)
	{
		return INT_MAX-1;
	}
	if (coin==0)
	{
		return 0;
	}
	if (a[0]>coin)
	{
		return min_coin(a+1,n-1,coin);
	}
	else
	{
		int x=min_coin(a,n,coin-a[0])+1;
		int y=min_coin(a+1,n-1,coin);
		int ans=min(x,y);
		return ans;
	}
}
//MEMOIZATION:
int helper(int *a,int n,int coin,int **dp)
{
	if (n==0)
	{
		return INT_MAX-1;
	}
	if (coin==0)
	{
		return 0;
	}
	if (dp[n][coin]!=-1)
	{
		return dp[n][coin];
	}
	if (a[0]<=coin)
	{
		dp[n][coin]=min(1+helper(a,n,coin-a[0],dp),helper(a+1,n-1,coin,dp));
		return dp[n][coin];
	}
	else
		{
			dp[n][coin]=helper(a+1,n-1,coin,dp);
	return dp[n][coin];
		}
}
int min_coin1(int *a,int n,int coin)
{
	int **dp=new int *[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		dp[i]=new int[coin+1];
	}
	for (int i = 0; i < n+1; ++i)
	{
		for(int j=0;j<coin+1;j++)
			dp[i][j]=-1;
	}
	return helper(a,n,coin,dp);
}
//DP:
int min_coin2(int *a,int n,int coin)
{
	int **dp=new int *[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		dp[i]=new int [coin+1];
	}
	for (int i=1;i<n+1;++i)
	{
		dp[i][0]=0;
	}
	for (int i=0;i<coin+1;++i)
	{
		dp[0][i]=INT_MAX-1;
	}
	for (int i=1;i<n+1;i++)
	{
		for(int j=1;j<coin+1;j++)
		{

			if (a[i-1]<=j)
			{
				dp[i][j]=min(dp[i-1][j],1+dp[i][j-a[i-1]]);
			}
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][coin];
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
	int coin;
	cin>>coin;
	cout<<min_coin(a,n,coin)<<endl;
	cout<<min_coin1(a,n,coin)<<endl;
	cout<<min_coin2(a,n,coin);
} 