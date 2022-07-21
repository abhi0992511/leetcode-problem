#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int dp[n+1];

	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=0;i<=n;i++)
	{
		for(int j=1;j<=k&&i-j>=0;j++)
		{
			dp[i]+=dp[i-j];
		}
	}
	cout<<dp[n];
}