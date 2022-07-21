#include <bits/stdc++.h>
#include <string>
using namespace std;
//RECURSIVE:
int dp[123][123][123];
int max_blessing(string a,string b,int k,int m,int n,int i,int j)
{
	
	if(i==m||j==n)
		{
			if (k>0)
			{
				return INT_MIN;
			}
			else
				return 0;
		}
	if (a[i]==b[j])
	{
		if (k>0)
		{
			return max(a[i]+max_blessing(a,b,k-1,m,n,i+1,j+1),max(max_blessing(a,b,k,m,n,i+1,j),max_blessing(a,b,k,m,n,i,j+1)));
	
		}
		else
			return 0;
		}
	else
		return max(max_blessing(a,b,k,m,n,i+1,j),max_blessing(a,b,k,m,n,i,j+1));
}
//MEMOISED+RECURSIVE:
int max_blessing1(string a,string b,int k,int m,int n,int i,int j)
{
	
	if(i==m||j==n)
		{
			if (k>0)
			{
				return INT_MIN;
			}
			else
				return 0;
		}
		if (dp[i][j][k]!=-1)
		{
		   return dp[i][j][k];
		}
	if (a[i]==b[j])
	{
		if (k>0)
		{
			return  dp[i][j][k]= max(a[i]+max_blessing1(a,b,k-1,m,n,i+1,j+1),max(max_blessing1(a,b,k,m,n,i+1,j),max_blessing1(a,b,k,m,n,i,j+1)));
	
		}
		else
			return 0;
		}
	else
		return dp[i][j][k]= max(max_blessing1(a,b,k,m,n,i+1,j),max_blessing1(a,b,k,m,n,i,j+1));
}
int main()
{
	string a,b;
	cin>>a>>b;
	int k;
	cin>>k;
	memset(dp,-1,sizeof(dp));
	int m=a.length();
	int n=b.length();
	cout<<max_blessing1(a,b,k,m,n,0,0)<<endl;
    int  x=max_blessing(a,b,k,m,n,0,0);
     if(x<0)
     	cout<<0;
     else
     	cout<<x;
  
}