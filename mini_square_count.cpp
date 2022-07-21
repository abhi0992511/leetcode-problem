#include <bits/stdc++.h>
using namespace std;
int dp[1001];
int min_square_count(int n)
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
		int temp=min_square_count(n-i*i);
		ans=min(ans,temp);
	}
	dp[n]=ans+1;
	return dp[n];
}
int main()
{
	int n;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	cout<<min_square_count(n);
}