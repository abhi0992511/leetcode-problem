#include<bits/stdc++.h>
using namespace std;
//RECURSION:
int max_coin1(int n)
{
	if (n<12)
	{
		return n;
	}
	return max_coin1(n/2)+max_coin1(n/3)+max_coin1(n/4);
}
//DP:
int max_coin2(int n)
{
	int*dp=new int [n+1];
	for(int i=0;i<n+1;i++)
	{
		dp[i]=i;
		dp[i]=max(dp[i],dp[i/2]+dp[i/3]+dp[i/4]);
	}
	return dp[n];
}
//MEMOISATION:
int max_coin(int n,map<int ,int>&dp)
{
	if (n<12)
	{
		return dp[n]=n;
	}
	if (dp.find(n)!=dp.end())
	{
		return dp[n];
	}
	return dp[n]=max(n,max_coin(n/2,dp)+max_coin(n/3,dp)+max_coin(n/4,dp));
}
int main()
{
	int n;
	cin>>n;
	map<int,int>dp;
	cout<<max_coin(n,dp)<<endl;
	cout<<max_coin2(n)<<endl;
	cout<<max_coin1(n)<<endl;
	
}