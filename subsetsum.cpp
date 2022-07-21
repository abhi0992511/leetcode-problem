#include <bits/stdc++.h>
using namespace std;
//RECURSION:
bool subset(int *a,int n,int sum)
{
	if(n==0&&sum==0)
		return true;
	if(n==0)
		return false;
	if (a[0]>sum)
	{
		return subset(a+1,n-1,sum);
	}
	else
	{
	 return subset(a+1,n-1,sum-a[0])||subset(a+1,n-1,sum);
	  
	}
}
//MEMOIZATION;
bool subset1(int *a,int n,int sum,int **dp)
{
	if(n==0&&sum==0)
		return true;
	if (n==0)
	{
		return false;
	}
	if (dp[n][sum]!=-1)
	{
		return dp[n][sum];
	}
	if (a[0]>sum)
	{
		dp[n][sum]=subset1(a+1,n-1,sum,dp);
		return dp[n][sum];
	}
	else
	{
		int x=subset1(a+1,n-1,sum-a[0],dp);
		int y=subset1(a+1,n-1,sum,dp);
		if (x==1||y==1)
		{
			return dp[n][sum]=true;
		}
		else
			return dp[n][sum]=false;
	}
}
bool helper(int *a,int n,int sum)
{
	int **dp=new int *[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		dp[i]=new int [sum+1];
	}
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
			dp[i][j]=-1;
	}
	return subset1(a,n,sum,dp);
}
//DP:
bool subset2(int *a,int n,int sum)
{
	int **dp=new int *[n+1];
	for(int i=0;i<n+1;i++)
		dp[i]=new int [sum+1];
	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < sum+1; ++j)
		{
			if(i==0)
				dp[i][j]=false;
			else if(j==0)
		   		dp[i][j]=true;
			 else if (a[i-1]<=j)
			{
				dp[i][j]=max(dp[i-1][j-a[i-1]],dp[i-1][j]);
			}
			else{
					dp[i][j]=false;
			}
		}
	}
	return dp[n][sum];
}
int main()
{
	int n;
	cin>>n;
	int *a=new int [n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int sum;
	cin>>sum;
	bool x=subset(a,n,sum);
	cout<<x<<endl;
	cout<<helper(a,n,sum)<<endl;
	cout<<subset2(a,n,sum);
}