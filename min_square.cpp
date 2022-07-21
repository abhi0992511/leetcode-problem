#include <bits/stdc++.h>
using namespace std;
//RECURSIVE:
int min_sq(int n)
{
	if (n==0)
	{
		return 0;
	}
	int ans=INT_MAX;
	for (int i=1;i*i<=n ;++i)
	{
	int temp=min_sq(n-i*i);
	  ans=min(ans,temp);	
	}
	int myans=ans+1;
	return myans;
}
//MEMOISATION:
int min_sq1(int n,int *dp)
{
	if (n==0)
	{
		return 0;
	}
	if (dp[n]!=-1)
	{
		return dp[n];
	}
	int ans=INT_MAX;
	for (int i =1;i*i<=n; ++i)
	{
		int temp=min_sq1(n-i*i,dp);
		ans=min(ans,temp);
	}
	dp[n]=ans+1;
	return dp[n];
}
//ITERATIVE:
int min_sq2(int n)
{
	int *dp=new int [n+1];
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	dp[3]=3;
	for (int i=4;i<=n; ++i)
	{
		dp[i]=i;
		for(int j=1;j*j<=ceil(i);j++)
		{
			int temp=j*j;
			if(temp>i)
			{
				break;
			}
			else
				dp[i]=1+min(dp[i],dp[i-j*j]);
		}
	}
	return dp[n];
}
int min_sq3(int n)
{
	int *dp=new int[n+1];
	dp[0]=0;
	for (int i =1; i<=n; ++i)
	{
		int ans=INT_MAX;
		for(int j=1;j*j<=i;j++)
		{
			int currans=dp[i-j*j];
			if (ans>currans)
			{
				ans=currans;
			}
		}
		dp[i]=1+ans;
	}
	return dp[n];

}
int main()
{
	int n;
	cin>>n;
	if(n<=3)
		cout<<n;
    
    int *dp=new int[n+1];
    for (int i = 0; i < n+1; ++i)
    {
    	dp[i]=-1;
    }
    cout<<min_sq3(n)<<endl;
    cout<<min_sq1(n,dp)<<endl;
    cout<<min_sq(n)<<endl;
}