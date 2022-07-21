#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
//RECURSIVE:
int maximum_value(vector<int>coin,int i,int j)
{
	if(i>=coin.size()||j<=0)
		return 0;
	if(i==j)
		return coin[i];
	if(i+1==j)
		return max(coin[i],coin[j]);
	return max(coin[i]+min(maximum_value(coin,i+1,j-1),maximum_value(coin,i+2,j)),
	coin[j]+min(maximum_value(coin,i+1,j-1),maximum_value(coin,i,j-2))
	);
}
//RECURSIVE+MEMOISATION:
int maximum_value1(vector<int>coin,int i,int j)
{
	if(i>=coin.size()||j<=0)
		return 0;
	if(i==j)
		return coin[i];
	if(i+1==j)
		return max(coin[i],coin[j]);
	if(dp[i][j]!=-1)
		return dp[i][j];
	return dp[i][j]= max(coin[i]+min(maximum_value1(coin,i+1,j-1),maximum_value1(coin,i+2,j)),
	coin[j]+min(maximum_value1(coin,i+1,j-1),maximum_value1(coin,i,j-2))
	);
}
int main()
{
	int n;
	cin>>n;
	vector<int>coin(n);
	for(int i=0;i<n;i++)
		cin>>coin[i];
	memset(dp,-1,sizeof(dp));
	cout<<maximum_value1(coin,0,n-1)<<endl;
	cout<<maximum_value(coin,0,n-1);
}