#include <bits/stdc++.h>
using namespace std;
//ALL ARE LCS VARIATIONS:
int lrs(string a,string b,int m,int n,int **dp)
{
	if (m==0||n==0)
	{
		return 0;
	}
	if (dp[m][n]!=-1)
	{
		return dp[m][n];
	}
	if (a[m-1]==b[n-1]&&m!=n)
	{
		dp[m][n]=lrs(a,b,m-1,n-1,dp)+1;
		return dp[m][n];
	}
	else
	{
		dp[m][n]=max(lrs(a,b,m-1,n,dp),lrs(a,b,m,n-1,dp));
		return dp[m][n];
	}
}
int main()
{
	string a,b;
	cin>>a;
	b=a;
	int m,n;
	m=a.length();
	n=b.length();
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
	cout<<lrs(a,b,m,n,dp);

}