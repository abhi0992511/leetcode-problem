#include <bits/stdc++.h>
using namespace std;
string scs(string a,string b,int m,int n)
{
	int **dp=new int *[m+1];
	for (int i = 0; i < m+1; ++i)
	{
	  dp[i]=new int [n+1];
	}
	for (int i = 0; i < m+1; ++i)
	{
		for(int j=0;j<n+1;j++)
		{
			if (i==0||j==0)
			{
				dp[i][j]=0;
				continue;
			}
			if (a[i-1]==b[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}
	string res="";
	int i=m;
	int j=n;
	while(i>0&&j>0)
	{
		if (a[i-1]==b[j-1])
		{
			//res.push_back(a[i-1]);
			res=res+a[i-1];
			i--;
			j--;
		}
		else
		{
			if (dp[i-1][j]>dp[i][j-1])
			{
				res=res+a[i-1];
				i--;
			}
			else
				{
					res=res+b[j-1];
					j--;
				}
		}
	}
	while(i>0)
	{
		res=res+a[i];
		i--;
	}
	while(j>0)
	{
		res=res+b[j];
		j--;
	}
	reverse(res.begin(),res.end());
	
	return res;



}
int main()
{
	string a,b;
	cin>>a>>b;
	int m,n;
	m=a.length();
	n=b.length();
	cout<<scs(a,b,m,n);
}