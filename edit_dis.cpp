#include <bits/stdc++.h>
#include <string.h>
using namespace std;
//RECURSIVE:
int edit(string s,string t)
{
	if (s.length()==0||t.length()==0)
	{
		return max(s.size(),t.size());
	}
	int ans;
	if (s[0]==t[0])
	{
		ans=edit(s.substr(1),t.substr(1));
		return ans;
	}
	else{
		int x=edit(s.substr(1),t.substr(1))+1;
		int y=edit(s.substr(1),t)+1;
		int z=edit(s,t.substr(1))+1;
		ans=min(x,min(y,z));
	}
	return ans;
}
//MEMOISATION:
int helper(string s,string t ,int **dp)
{ 
	int m=s.length();
	int n=t.length();
	if (m==0||n==0)
	{
		return max(m,n);
	}
	if (dp[m][n]!=-1)
	{
		return dp[m][n];
	}
	if (s[0]==t[0])
	{
		return helper(s.substr(1),t.substr(1),dp);
	}
	else
	{
		int x=helper(s.substr(1),t.substr(1),dp)+1;
		int y=helper(s.substr(1),t,dp)+1;
		int z=helper(s,t.substr(1),dp)+1;
		int ans=min(x,min(y,z));
		dp[m][n]=ans;
	}
	return dp[m][n];
	
}
int edit2(string s,string t)
{
	int m=s.length();
	int n=t.length();
	int **dp=new int *[m+1];
	for (int i = 0; i < m+1; ++i)
	{
		dp[i]=new int[n+1];
	}
	for (int i = 0; i < m+1; ++i)
	{
		for(int j=0;j<n+1;j++)
		{
			dp[i][j]=-1;
		}
	}
	return helper(s,t,dp);
}
int edit3(string s,string t)
{
	int m=s.length();
	int n=t.length();
	int **dp=new int *[m+1];
	for (int i = 0; i < m+1; ++i)
	{
		dp[i]=new int [n+1];
	}
	for (int i = 0; i < n+1; ++i)
	{
		dp[0][i]=i;
	}
	for (int i = 0; i < n+1; ++i)
	{
		dp[i][0]=i;
	}
	for (int i = 1; i < m+1; ++i)
	{
		for(int j=1;j<n+1;j++)
		{
			if (s[m-i]==t[n-j])
			{
		        dp[i][j]=dp[i-1][j-1];
			}
			else
			{
				int x=dp[i-1][j-1]+1;
				int y=dp[i-1][j]+1;
				int z=dp[i][j-1]+1;
				dp[i][j]=min(x,min(y,z));
			}
		}
	}
	return dp[m][n];
}
int main()
{
	string s,t;
	cin>>s>>t;
	
	cout<<edit2(s,t)<<endl;
	cout<<edit3(s,t)<<endl;
	int ans=edit(s,t);
	cout<<ans<<endl;
}