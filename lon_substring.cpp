#include <bits/stdc++.h>
#include <string>
using namespace std;
//RECURSIVE:
int lcss(string s,string a)
{
	if (s.length()==0||a.length()==0)
	{
		return 0;

	}
	if (s[0]==a[0])
	{
		return lcss(s.substr(1),a.substr(1))+1;
	}
	else
		return max(lcss(s.substr(1),a),lcss(s,a.substr(1)));
}
//DP:
int lcs2(string s,string a)
{
	int m=s.length();
	int n=a.length();
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
	for (int i = 1; i < m+1; ++i)
	{
		for (int j=1;j<n+1;j++)
		{
			if (s[i-1]==a[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			dp[i][j]=dp[i][j-1];
		}
	}
	return dp[m][n];
}
//MEMOISATION:
int helper(string s,string a,int **dp)
{
	if (s.length()==0||a.length()==0)
	{
		return 0;
	}
	if (dp[s.length()][a.length()]!=-1)
	{
		return dp[s.length()][a.length()];
	}
	if (s[0]==a[0])
	{
		dp[s.length()][a.length()]=helper(s.substr(1),a.substr(1),dp)+1;
		return dp[s.length()][a.length()];
	}
	else
		{
			dp[s.length()][a.length()]=helper(s.substr(1),a.substr(1),dp);
              return dp[s.length()][a.length()];
		}
}
int lcss1(string s,string a)
{
	int **dp=new int *[s.length()+1];
	for (int i = 0; i < s.length()+1; ++i)
	{
		dp[i]=new int [a.length()+1];
	}
	for (int i = 0; i < s.length()+1; ++i)
	{
		for(int j=0;j<a.length()+1;j++)
			dp[i][j]=-1;
	}
	return helper(s,a,dp);
}
int main()
{
	string s;
	string a;
	cin>>s>>a;
	cout<<lcss(s,a)<<endl;
	cout<<lcss1(s,a)<<endl;
	cout<<lcs2(s,a);
}