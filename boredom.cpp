#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
using namespace std;
long long int boredom(vector<int>a)
{
	unordered_map<int,long long int>mp;
	for(int i=0;i<a.size();i++)
		  mp[a[i]]++;
	vector<long long int>dp(100001);
	dp[0]=0;
	dp[1]=mp[1];
	for(int i=2;i<=100001;i++)
	{
		dp[i]=max(dp[i-2]+i*mp[i],dp[i-1]);
	}
	return dp[100001];
}
int main()
{
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<boredom(a);
}