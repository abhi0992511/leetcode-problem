#include <bits/stdc++.h>
using namespace std;
//RECURSIVE:
int kanp(int *w,int *v,int n,int value)
{
	if(n==0||value==0)
	{
	 return 0;
	}
	if(w[0]>value)
	{
		return kanp(w+1,v+1,n-1,value);
	}

	int x=kanp(w+1,v+1,n-1,value-w[0])+v[0];
	int y=kanp(w+1,v+1,n-1,value);
	int ans=max(x,y);
	return ans;
}
//MEMOISATION:
int helper(int *w,int *v,int n,int value,int **dp)
{
	if(n==0||value==0)
	{
		return 0;
	}
	int ans;
	if (dp[value][n]!=-1)
	{
		return dp[value][n];
	}
	if(w[0]>value)
		{
			ans=helper(w+1,v+1,n-1,value,dp);
			dp[value][n]=ans;
			return ans;
		}
    
    int x=helper(w+1,v+1,n-1,value-w[0],dp)+v[0];
	int y=helper(w+1,v+1,n-1,value,dp);
	 ans=max(x,y);
	dp[value][n]=ans;
	return ans;

}
int knap1(int *w,int *v,int n,int value)
{
	int **dp=new int *[value+1];

	for(int i=0;i<value+1;i++)
	{
		dp[i]=new int [n+1];
	}
	//memset(dp,-1,sizeof(dp));
	for (int i = 0; i < value+1; ++i)
	{
		for(int j=0;j<n+1;j++)
		{
			dp[i][j]=-1;
		}
	}
return	helper(w,v,n,value,dp);
}
//DP:
int knap2(int *w,int *v,int n,int value)
{
	int **dp=new int *[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		dp[i]=new int[value+1];
	}
	for (int i = 0; i < n+1; i++)
	{
		for(int j=0;j<value+1;j++)
		{
			if (i==0||j==0)
			{
			dp[i][j]=0;
			}
			else if (w[i-1]<=j)
			{
				int x=v[i-1]+dp[i-1][j-w[i-1]];
				int y=dp[i-1][j];
				dp[i][j]=max(x,y);
			}
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][value];
}
int main()
{
	int n;
	cin>>n;
	int *w=new int [n];
	int * v=new int [n];
	for(int i=0;i<n;i++)
	{
		cin>>w[i];
	}
	for(int i=0;i<n;i++)b:

	{
		cin>>v[i];
	}
	int value;
	cin>>value;
	int ans=kanp(w,v,n,value);
	cout<<ans<<endl;
	cout<<knap1(w,v,n,value)<<endl;
	cout<<knap2(w,v,n,value);

}