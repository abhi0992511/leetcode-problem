#include <bits/stdc++.h>
#include <string>
using namespace std;
//RECURSIVE:
int dp[101][101];
int short_sequence(string s,string a)
{
	if (s.length()==0||a.length()==0)
	{
	  return max(s.length(),a.length());
	}
	if(s[0]==a[0])
		return 1+short_sequence(s.substr(1),a.substr(1));
	else
		return 1+min(short_sequence(s,a.substr(1)),short_sequence(s.substr(1),a));
}
int short_sequence(string s,string a,int m,int n)
{
	if (s.length()==0||a.length()==0)
	{
	  return max(s.length(),a.length());
	}
	if (dp[m][n]!=-1)
	{
		return dp[m][n];
	}
	if(s[0]==a[0])
		return dp[m][n]= 1+short_sequence(s.substr(1),a.substr(1),m-1,n-1);
	else
		return dp[m][n]= 1+min(short_sequence(s,a.substr(1),m,n-1),short_sequence(s.substr(1),a,m-1,n));
}
int main()
{
	string s,a;
	cin>>s>>a;
	memset(dp,-1,sizeof(dp));
	int m=s.length();
	int n=a.length();
	cout<<short_sequence(s,a,m,n)<<endl;
	cout<<short_sequence(s,a);
}