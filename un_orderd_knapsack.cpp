#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *val=new int [n];
	int *wt=new int [n];
	for (int i = 0; i < n; ++i)
	{
		cin>>wt[i];
	}

	for (int i = 0; i < n; ++i)
	{
		cin>>val[i];
	}
	int target;
	cin>>target;
	int *dp=new int[target+1];
	dp[0]=0;
	
	
	for (int i = 1; i < target+1; i++)
	{
		int maxi=0;
		for(int j=0;j<n;j++)
		{  
			
			if (wt[j]<=i)
			{
				int rcap=i-wt[j];
				int rval=dp[rcap];
				int tval=rval+val[j];
				if (tval>maxi)
				{
					maxi=tval;
				}

			}
		}
		dp[i]=maxi;
		
	}
	
	
	for (int i = 0; i < target+1; ++i)
	{
       cout<<dp[i]<<" ";
	}
}