#include <bits/stdc++.h>
using namespace std;
int dp[101][101][2];
//RECURSIVE:
int fun(int n,int k,int lastvalue)
{
	if (n==0)
	{
		return 0;
	}
	if (n==1)
	{
		return k==0?1:0;
	}
	if (lastvalue==1)
	{
		return fun(n-1,k-1,1)+fun(n-1,k,0);
	}
	else
		return fun(n-1,k,0)+fun(n-1,k,1);
}
//RECURSIVE+MEMOISED:
int fun1(int n,int k,int lastvalue)
{
	if (n==0)
	{
		return 0;
	}
	if (n==1)
	{
		return k==0?1:0;
	}
	if (dp[n][k][lastvalue]!=-1)
	{
		return dp[n][k][lastvalue];
	}
	if (lastvalue==1)
	{
		dp[n-1][k-1][1]=fun1(n-1,k-1,1);
		dp[n-1][k][0]=fun1(n-1,k,0);
		return dp[n-1][k-1][1]+dp[n-1][k][0];
	}
	else
	{
		dp[n-1][k][0]=fun1(n-1,k,0);
		dp[n-1][k][1]=fun1(n-1,k,1);
		return dp[n-1][k][1]+dp[n-1][k][0];
	}
}
//DP:
int num_bits(int n,int k)
{
	int dp[n+1][k+1][2];
	memset(dp,0,sizeof(dp));
	 dp[1][0][0]=1;
	 dp[1][0][1]=1;
	 for(int i=2;i<n+1;i++)
	 {
	 	for(int j=0;j<k+1;j++)
	 		{
	 			dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
	 	        dp[i][j][1]=dp[i-1][j][0];
	 	        if(j-1>=0)
	 	        	dp[i][j][1]+=dp[i-1][j-1][1];
	 		}
	 }
	 return dp[n][k][1]+dp[n][k][0];
}
int main()
{
	int n,k;
	cin>>n>>k;
	memset(dp,-1,sizeof(dp));
	cout<<num_bits(n,k)<<endl;
	cout<<fun1(n,k,0)+fun1(n,k,1)<<endl;
	cout<<fun(n,k,0)+fun(n,k,1);
}