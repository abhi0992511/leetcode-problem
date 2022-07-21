#include <bits/stdc++.h>
using namespace std;
int cherry_pick(int **a,int m,int n)
{
	int **dp=new int *[m];
	for (int i = 0; i < m; ++i)
	{
		dp[i]=new int [n];
	}
	dp[m-1][n-1]=1;
	for(int i=m-2;i>=0;i--)
	{
		if (a[i][n-1]==1)
		{
		  dp[i][n-1]=dp[i+1][n-1]+1;
		}
		else if (a[i][n-1]==0)
		{
			dp[i][n-1]=dp[i+1][n-1];
		}
		else
			dp[i][n-1]=0;
	}
	for(int i=n-2;i>=0;i--)
	{
		if (a[m-1][i]==1)
		{
		  dp[m-1][i]=dp[m-1][i+1]+1;
		}
		else if (a[m-1][i]==0)
		{
			dp[m-1][i]=dp[m-1][i];
		}
		else
			dp[m-1][i]=0;
	}
	for(int i=m-2;i>=0;i--)
	{
		for(int j=n-2;j>=0;j--)
		{
			if (a[i][j]==1)
			{
				dp[i][j]=max(dp[i+1][j],dp[i][j+1])+1;
				a[i][j]=0;
			}
			else if (a[i][j]==0)
			{
				dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
			}
			else
				dp[i][j]=0;
		}
	}
	return dp[0][0];
}
int main()
{
	int m,n;
	cin>>m>>n;
	int **a=new int *[m];
	for (int i = 0; i < m; ++i)
	{
		a[i]=new int [n];
	}
	for (int i = 0; i < m; ++i)
	{
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	}
	cout<<cherry_pick(a,m,n);
}