#include <bits/stdc++.h>
#include <string.h>
#include <cstring>
using namespace std;
//RECURSIVE:
int lcs(string s,string a,int m,int n)
{
	if (m==0||n==0)
	{
		return 0;
	}
	if (s[m-1]==a[n-1])
	{
		return 1+lcs(s,a,m-1,n-1);
	}
	else
	{
		int x=lcs(s,a,m-1,n);
		int y=lcs(s,a,m,n-1);
		//int z=lcs(s,a,m-1,n-1);
		return max(x,y);
	}
}
void lcs3(string s,string a,int m,int n)
{
	if (m==0||n==0)
	{
		return;
	}
	if (s[0]==a[0])
	{
	     cout<<s[0]<<" ";
	     lcs3(s.substr(1),a.substr(1),m-1,n-1);
	}
	else
	{
		lcs3(s,a.substr(1),m,n-1);
		lcs3(s.substr(1),a,m-1,n);
	}
}
//MEMOISATION:
int helper(string s,string a,int m,int n,int **dp)
{
	if (m==0||n==0)
	{
		return 0;
	}
	if (dp[m][n]!=-1)
	{
		return dp[m][n];
	}
	if (s[0]==a[0])
	{
		dp[m][n]=1+helper(s.substr(1),a.substr(1),m-1,n-1,dp);
		return dp[m][n];
	}
	else
	{
		int x=helper(s.substr(1),a,m-1,n,dp);
		int y=helper(s,a.substr(1),m,n-1,dp);
		dp[m][n]=max(x,y);
		return dp[m][n];
	}
}
int lcs1(string s,string a,int m,int n)
{
	int **dp=new int*[m+1];
	for (int i = 0; i < m+1; ++i)
	{
		dp[i]=new int [n+1];
	}
for (int i = 0; i < m+1; ++i)
{
	for(int j=0;j<n+1;j++)
		dp[i][j]=-1;
}
//memset(dp,-1,((m+1)*(n+1))*sizeof(*dp));
	return helper(s,a,m,n,dp);
}
//DP:
int lcs2(string s,string a,int m,int n)
{
	int **dp=new int *[m+1];
	for (int i = 0; i < m+1; ++i)
	{
	  dp[i]=new int [n+1];

	}
	for (int i = 0; i < m+1; ++i)
	{
		dp[i][0]=0;
	}
	for (int i = 0; i < n+1; ++i)
	{
		dp[0][i]=0;
	}
	for (int i =1; i < m+1; ++i)
	{
		for (int j=1;j<n+1;j++)
		{
			if (s[i-1]==a[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
			}
			else
			{
				int x=dp[i-1][j];
				int y=dp[i][j-1];
				dp[i][j]=max(x,y);
			}
		}
	}
	return dp[m][n];
}
int main()
{
	string s,a;
	cin>>s>>a;
	int m=s.length();
	int n=a.length();
	cout<<lcs1(s,a,m,n)<<endl;
	cout<<lcs2(s,a,m,n)<<endl;
	cout<<lcs(s,a,m,n)<<endl;
	lcs3(s,a,m,n);
	
}