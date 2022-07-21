#include <bits/stdc++.h>
using namespace std;
long long dp[1001][1001];
//RECURSIVE+MEMOISED:
long long binomial_cofi(int n,int k)
{
	if(dp[n][k]!=-1)
		return dp[n][k];
	if(n-k<0)
	{
		dp[n][k]=0;
		return dp[n][k];
	}
	if(n==0||k==0)
		{
			dp[n][k]=1;
			return dp[n][k];
		}
	return dp[n][k]= binomial_cofi(n-1,k-1)+binomial_cofi(n-1,k);
}
int main()
{
	int n,k;
	cin>>n>>k;
	memset(dp,-1,sizeof(dp));
	cout<<binomial_cofi(n,k);
}