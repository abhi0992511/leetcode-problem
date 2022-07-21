#include <bits/stdc++.h>
using namespace std;
//VARIATION OF LCS:
int lcs(string a,string b,int m,int n,int**dp)
{
	if (m==0||n==0)
	{
		return 0;
	}
	if (dp[m][n]!=-1)
	{
		return dp[m][n];
	}
	if (a[m-1]==b[n-1])
	{
		return dp[m][n]=lcs(a,b,m-1,n-1,dp)+1;
	}
	else
	{
		return dp[m][n]=max(lcs(a,b,m-1,n,dp),lcs(a,b,m,n-1,dp));
	}
}
int spm(string a,string b,int m,int n)
{
	int **dp=new int *[m+1];
	for (int i = 0; i < m+1; ++i)
	{
		dp[i]=new int[n+1];
	}
	for (int i = 0; i < m+1; ++i)
	{
		for(int j=0;j<n+1;j++)
			dp[i][j]=-1;
	}
	int x=lcs(a,b,m,n,dp);
	return m-x;
}
int main()
{
	string a,b;
	cin>>a>>b;
	int m=a.length();
	int n=b.length();
	cout<<spm(a,b,m,n);
}