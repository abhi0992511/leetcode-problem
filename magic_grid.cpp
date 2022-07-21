#include <bits/stdc++.h>
using namespace std;
int dp[200][200];
//RECURSIVE:
int magic_grid(int **a,int m,int n,int i,int j)
{   
	if(i>=m||j>=n)
		return INT_MAX;

	if (i==m-1&&j==n-1)
	{
		return a[i][j]<=0?abs(a[i][j])+1:1;
	}
		
	int ans1=magic_grid(a,m,n,i+1,j);
	int ans2=magic_grid(a,m,n,i,j+1);
	int ans=min(ans1,ans2)-a[i][j];

	return ans<=0?1:ans;
	
}
//MEMOISATION:
int magic_grid1(int **a,int m,int n,int i,int j)
{   
	if(i>=m||j>=n)
		return INT_MAX;

	if (i==m-1&&j==n-1)
	{
		return a[i][j]<=0?abs(a[i][j])+1:1;
	}
	if (dp[i][j]!=-1)
	{
		return dp[i][j];
	}
		
	int ans1=magic_grid1(a,m,n,i+1,j);
	int ans2=magic_grid1(a,m,n,i,j+1);
	int ans=min(ans1,ans2)-a[i][j];

	return dp[i][j]= ans<=0?1:ans;
	
}
//BOTTOM_UP:
int magic_grid(int **a,int m,int n)
{
	int **dp=new int * [m];
	for (int i = 0; i < m; ++i)
	{
		dp[i]=new int [n];
	}
	dp[m-1][n-1]= a[m-1][n-1]<=0?abs(a[m-1][n-1])+1:1;
	for (int i =m-2;i>=0;i--)
	{
	 dp[i][n-1]=max(dp[i+1][n-1]-a[i][n-1],1);

	}
	for (int i =n-2;i>=0;i--)
	{
	 dp[m-1][i]=max(dp[m-1][i+1]-a[m-1][i],1);
	 
	}
	for (int i =m-2;i>=0;i--)
	{
		for(int j=n-2;j>=0;j--)
		{
			int minans=min(dp[i+1][j],dp[i][j+1]);
			dp[i][j]=max(minans-a[i][j],1);
		}
	}
	return dp[0][0];
}
int main()
{
	int n,m;
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
	memset(dp,-1,sizeof(dp));
	cout<<magic_grid(a,m,n)<<endl;//bottom_up
	cout<<magic_grid1(a,m,n,0,0)<<endl;//memoisation:
	cout<<magic_grid(a,m,n,0,0);//recursive
}