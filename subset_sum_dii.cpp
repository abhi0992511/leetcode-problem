#include <bits/stdc++.h>
using namespace std;
//RECURSIVE:
bool subdiff(int *a,int n,int sum,bool **&dp)
{


	if(n==0)
		return false;
	if(n==0&&sum==0)
		return true;
	
	if (dp[n][sum]!=false)
	{
		return dp[n][sum];
	}
	else
	{
		dp[n][sum]=subdiff(a,n,sum-1,dp);
		return dp[n][sum];
	}

}
//DP:
int subdiff1(int *a,int n,int sum)
{
	bool **dp=new bool *[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		dp[i]=new bool [sum+1];
	}
	for (int j=0;j<sum+1;j++)
	{
		dp[0][j]=false;
	}
	for(int i=0;i<n+1;i++)
		dp[i][0]=true;
	for (int i =1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(a[i-1]<=j)
			{
				dp[i][j]=dp[i-1][j-a[i-1]];
			}
			else
				dp[i][j]=dp[i-1][j];
		
		}
    }
    int ans=INT_MAX;
    for (int i=sum/2;i>=0;i--)
    {
    	if(dp[n][i]==true)
    	{
    		ans=sum-2*i;
    		break;
    	}
    }
    return ans;
}
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int sum=0;
	for(int i=0;i<n;i++)
		sum=sum+a[i];
	bool **dp=new bool *[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		dp[i]=new bool [sum+1];
	}
	for (int i = 0; i < n+1; ++i)
	{
		for(int j=0;j<sum+1;j++)
			dp[i][j]=false;
	}
	cout<<subdiff(a,n,sum,dp)<<endl;
	cout<<subdiff1(a,n,sum)<<endl;
	for(int i=0;i<n+1;i++)
	{
		for (int j=0;j<sum+1;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}