#include <bits/stdc++.h>
using namespace std;
//USING DP:
int main()
{
	int n;
	cin>>n;
	int *wt=new int[n];
	int *val=new int [n];
	for (int i = 0; i < n; ++i)
	{
		cin>>wt[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>val[i];
	}
	int **dp=new int*[n+1];
	int target;
	cin>>target;
	for (int i = 0; i < n+1; i++)
	{
		dp[i]=new int [target+1];
	}
	 for (int i = 0; i < n+1; ++i)
    {
    	for (int j = 0; j < target+1; ++j)
    	{
           dp[i][j]=0;
    	}
    
    }
	for (int i = 1; i < n+1; i++)
	{
		for (int j = 1; j < target+1; j++)
		{
				if (j>=wt[i-1])
				{   
					int rem=j-wt[i-1];
					if (dp[i-1][rem]+val[i-1]>dp[i-1][j])
					{
						dp[i][j]=dp[i-1][rem]+val[i-1];
					}
					else
						dp[i][j]=dp[i-1][j];
				}
				else
				   dp[i][j]=dp[i-1][j];
			
		}
	}
	 for (int i = 0; i < n+1; ++i)
    {
    	for (int j = 0; j < target+1; ++j)
    	{
          cout<< dp[i][j]<<" ";
    	}
    	cout<<endl;
    
    }

}