#include<bits/stdc++.h>
using namespace std;
//RECURSIVE:
int un_kanp(int *w,int *v,int n,int target)
{
	if (target==0||n==0)
	{
		return 0;
	}

	if (w[0]>target)
	{
		return un_kanp(w+1,v+1,n-1,target);
	}
	else
	{
	int x=v[0]+un_kanp(w,v,n,target-w[0]);
		int y=un_kanp(w+1,v+1,n-1,target);
		int ans=max(x,y);
		return ans;
	}
}
//MEMOIZATION:
int helper(int *w,int *v,int n,int target,int **dp)
{
	if (target==0||n==0)
	{
		return 0;
	}
	if (dp[n][target]!=-1)
	{
		return dp[n][target];
	}
	if (w[0]>target)
	{
		dp[n][target]=helper(w+1,v+1,n-1,target,dp);
		return dp[n][target];
	}
	else
	{
		int x=v[0]+helper(w,v,n,target-w[0],dp);
		int y=helper(w+1,v+1,n-1,target,dp);
		dp[n][target]=max(x,y);
		return dp[n][target];
	}
}
int un_kanp1(int *w,int *v,int n,int target)
{
	int **dp=new int *[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		dp[i]=new int[target+1];
	}
	for (int i = 0; i < n+1; ++i)
	{
		for(int j=0;j<target+1;j++)
			dp[i][j]=-1;
	}
return helper(w,v,n,target,dp);
}
//DP:
int un_kanp2(int *w,int *v,int n,int target)
{
	int **dp=new int *[n+1];
	for (int i = 0; i < n+1; ++i)
	{
	  dp[i]=new int [target+1];
	}
	for (int i = 0; i < n+1; ++i)
	{
		dp[i][0]=0;
	}
	for (int i = 0; i < target+1; ++i)
	{
		dp[0][i]=0;
	}
	for (int i = 1; i < n+1; ++i)
	{
		for(int j=1;jtry<target+1;j++)
		{
			if (w[i-1]<=j)
			{
		          dp[i][j]=max(v[i-1]+dp[i][j-w[i-1]],dp[i-1][j]);
			}
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][target];
}
int main()
{
	int n;
	cin>>n;
	int *w=new int [n];
	int *v=new int [n];
	for(int i=0;i<n;i++)
	{
		cin>>w[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	int target;
	cin>>target;
	cout<<un_kanp(w,v,n,target)<<endl;
	cout<<un_kanp1(w,v,n,target)<<endl;
	cout<<un_kanp2(w,v,n,target);

}