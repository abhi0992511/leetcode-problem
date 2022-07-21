#include <bits/stdc++.h>
using namespace std;
#include <cmath>
//USING_RECURSION:
int tree(int n)
{
	if (n<=1)
	{
		return 1;
	}
	int mod=(int)(pow(10,9))+7;

	int x=tree(n-1);
	int y=tree(n-2);
	int temp1=(int)(((long)(x)*x)%mod);
	int temp2=(int)((2*(long)(x)*y)%mod);
	int ans=(temp1+temp2)%mod;
	return ans;
}
//USING_MEMOISATION:
int tree1(int n,int *dp)
{
	if (n<=1)
	{
		return 1;
	}
	int mod=(int)(pow(10,9))+7;
	if(dp[n]!=-1)
	{
		return dp[n];
	}

	int x=tree1(n-1,dp);
	int y=tree1(n-2,dp);
	int temp1=(int)(((long)(x)*x)%mod);
	int temp2=(int)((2*(long)(x)*y)%mod);
	int ans=(temp1+temp2)%mod;
	dp[n]=ans;
	return ans;
}
//USING_DP:
int tree2(int n)
{
	int *dp=new int [n+1];
	dp[0]=1;
	dp[1]=1;
	for (int i = 2; i <n+1; ++i)
	{  
		int sum=0;
		for(int j=i-1;j<=0;j--)
		{
         sum=sum+dp[j];
		}
		dp[i]=sum;
	}
	return dp[n];
}
int main()
{
	int n;
	cin>>n;
	int *dp=new int[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		dp[i]=-1;
	}
	cout<<tree2(n);
}