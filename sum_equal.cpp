#include <bits/stdc++.h>

using namespace std;
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

int main()
{
	int n;
	cin>>n;
	int *a=new int [n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum=sum+a[i];
	}
	if(sum%2!=0)
		cout<<false;
	else
	cout<<helper(a,n,sum/2);

}