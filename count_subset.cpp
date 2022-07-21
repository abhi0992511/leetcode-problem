#include <bits/stdc++.h>
using namespace std;
//RECURSIVE
int count_seq(int *a,int n,int sum)
{
    if(n==0&&sum==0)
    	return 1;
    if (n==0)
    {
    	return 0;
    }
    if(a[0]>sum)
    	return count_seq(a+1,n-1,sum);
    else{
    	int x=count_seq(a+1,n-1,sum-a[0]);
    	int y=count_seq(a+1,n-1,sum);
    	return x+y;
    }


}
//MEMOIZATION:
int helper(int *a,int n,int sum,int **dp)
{
	if (n==0&&sum==0)
	{
		return 1;
	}
	if (n==0)
	{
		return 0;
	}
	if (dp[n][sum]!=-1)
	{
		return dp[n][sum];
	}
	if (a[0]>sum)
	{
		dp[n][sum]=helper(a+1,n-1,sum,dp);
		return dp[n][sum];
	}
	else
	{
		dp[n][sum]=helper(a+1,n-1,sum-a[0],dp)+helper(a+1,n-1,sum,dp);
		return dp[n][sum];
	}
}
int count_seq1(int *a,int n,int sum)
{
	int **dp=new int *[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		dp[i]=new int[sum+1];
	}
	for (int i = 0; i < n+1; ++i)
	{
		for(int j=0;j<sum+1;j++)
			dp[i][j]=-1;
	}
 return	helper(a,n,sum,dp);
}
//DP:
int count_seq2(int *a,int n,int sum)
{
	int **dp=new int* [n+1];
	for (int i = 0; i < n+1; ++i)
	{
		dp[i]=new int [sum+1];
	}
	for (int i = 0; i < n+1; i++)
	{
	  for(int j=0;j<sum+1;j++)
	  {
	  	if(i==0&&j==0)
	  		dp[i][j]=1;
	   else if (i==0)
	  	{
	  		dp[i][j]=0;
	  	}
	  else if (j==0)
	  	{
	  		dp[i][j]=1;
	  	}
	  	 else if(a[i-1]<=j)
	  		dp[i][j]=dp[i-1][j-a[i-1]]+dp[i-1][j];
	  	else
	  		dp[i][j]=dp[i-1][j];

	  	
	  }
	}
	return dp[n][sum];
	// for (int i = 0; i < n+1; ++i)
	// {
	// 	for(int j=0;j<sum+1;j++)
	// 		cout<<dp[i][j];
	// 	cout<<endl;
	// }
}


int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int  sum;
	cin>>sum;
	cout<<count_seq(a,n,sum)<<endl;
	cout<<count_seq1(a,n,sum)<<endl;
	cout<<count_seq2(a,n,sum);


}