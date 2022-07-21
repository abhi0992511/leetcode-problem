#include <bits/stdc++.h>
using namespace std;
//USING_RECURSION:
int no_coin(int *a,int n,int coin)
{
	if (n==0)
	{
		return 0;
	}
	if (coin<0)
	{
		return 0;
	}
	if (coin==0)
	{
	   return 1;

	}
	int output=no_coin(a,n,coin-a[0]);
	int sec=no_coin(a+1,n-1,coin);
	return output+sec;


}
//USING_MEMOISATION:
int no_coin1(int *a,int n,int coin,int **dp1)
{
	if (n==0)
	{
		return 0;
	}
	if (coin==0)
	{
		return 1;
	}
	if (coin<0)
	{
		return 0;
	}
	if (dp1[n][coin]!=-1)
	{
		return dp1[n][coin];
	}
	int first=no_coin1(a,n,coin-a[0],dp1);
	int sec=no_coin1(a+1,n-1,coin,dp1);
	dp1[n][coin]=first+sec;
	return first+sec;
}
//DP:
int no_coin2(int *a,int n,int coin)
{
	int **dp=new int *[n+1];
	for (int i = 0; i < n+1; i++)
	{
		dp[i]=new int[coin+1];
	
	}
	for (int i = 0; i < coin+1; ++i)
	{
		dp[0][i]=0;
	}
	for (int i = 0; i < n+1; ++i)
	{
		dp[i][0]=1;
	}

	for (int i = 1; i < n+1; i++)
	{
		for (int j=1;j<coin+1;j++)
	{
		if (a[i-1]<=j)
			{
				dp[i][j]=dp[i-1][j]+dp[i][j-a[i-1]];
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	return dp[n][coin];
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
	int coin;
	cin>>coin;
	int **dp1=new int *[n+1];
	for (int i = 0; i < n+1; i++)
	{
		dp1[i]=new int[coin+1];
	
	}
	for (int i = 0; i < n+1; ++i)
	{
		for(int j=0;j<coin+1;j++)
			dp1[i][j]=-1;
	}
	
	cout<<no_coin(a,n,coin)<<endl;
	cout<<no_coin1(a,n,coin,dp1)<<endl;
	cout<<no_coin2(a,n,coin);
}