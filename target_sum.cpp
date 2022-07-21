#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int target;
	cin>>target;
	bool **dp=new bool*[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		dp[i]=new bool [target+1];
	}
	for (int i=0;i<n+1;i++)
	{
		for (int j=0;j<target+1;j++)
		{
			if (i==0&&j==0)
			{
				dp[i][j]=true;
			}
			else if (i==0)
			{
				dp[i][j]=false;
			}
			else if (j==0)
			{
				dp[i][j]=true;
			}
			else
			{
				if (dp[i-1][j]==true)
				{
					dp[i][j]=true;
				}
				else
				{   
					int val=a[i-1];

					if (j>=a[i-1]&&dp[i-1][j-val]==true)
					{
						dp[i][j]=true;
					}
					else
						dp[i][j]=false;
				}
			}
		}
	}
	cout<<dp[n][target];
}