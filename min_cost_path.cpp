#include <bits/stdc++.h>
using namespace std;
//MEMOISATION:
int helper(int **in,int m,int n,int i,int j,int **dp)
{
  


  if(i==m-1&&j==n-1)
  	return in[i][j];
  if (i>=m||j>=n)
  {
  	return INT_MAX;
  }
  if(dp[i][j]!=-1)
  	return dp[i][j];



int x=helper(in,m,n,i,j+1,dp);
int y=helper(in,m,n,i+1,j+1,dp);
int z=helper(in,m,n,i+1,j,dp);
int ans=min(x,min(y,z))+in[i][j];
dp[i][j]=ans;
return ans;




}
int min_cost(int **in,int m,int n)
{

     int **dp=new int *[m];
     for (int i = 0; i < m; ++i)
     {
     	dp[i]=new int [n];

     }
     for (int i = 0; i < m; ++i)
     {
     	for (int j=0;j<n;j++)
     	{
     		dp[i][j]=-1;
     	}
     }
    // dp[0][0]=in[0][0];
return helper(in,m,n,0,0,dp);
}
//RECURSIVE:
int helper1(int **in,int m,int n,int i,int j)
{
  


  if(i==m-1&&j==n-1)
  	return in[i][j];
  if (i>=m||j>=n)
  {
  	return INT_MAX;
  }
  



int x=helper1(in,m,n,i,j+1);
int y=helper1(in,m,n,i+1,j+1);
int z=helper1(in,m,n,i+1,j);
int ans=min(x,min(y,z))+in[i][j];
return ans;




}
int min_cost1(int **in,int m,int n)
{

  
     
return helper1(in,m,n,0,0);
}
//DP:
int min_cost2(int **in,int m,int n)
{
	int **output=new int *[m];
	for (int i = 0; i < m; ++i)
	{
	    output[i]=new int[n];
	}
	
	output[m-1][n-1]=in[m-1][n-1];

	for (int i =n-2; i>=0 ;i--)
	{
		output[m-1][i]=in[m-1][i]+output[m-1][i+1];
	}
	for (int i=m-2; i>=0 ;i--)
	{
		output[i][n-1]=in[i][n-1]+output[i+1][n-1];
	}
	for (int i =m-2; i>=0; i--)
	{
		for (int j=n-2;j>=0;j--)
		{
			output[i][j]=min(output[i+1][j+1],min(output[i][j+1],output[i+1][j]))+in[i][j];
		}
	}
	int ans=output[0][0];
	
	return ans;
	

}
//TOP_DOWN:
int min_costs(int **in,int m,int n)
{
	int **dp=new int *[m+1];
	for (int i = 0; i < m+1; ++i)
	{
		dp[i]=new int [n+1];
	}
	for(int i=0;i<m+1;i++)
		 dp[i][0]=INT_MAX;
		for (int i = 0; i < n+1; ++i)
		{
			dp[0][i]=INT_MAX;
		}
		for(int i=1;i<m+1;i++)
		{
			for(int j=1;j<n+1;j++)
			{
				if(i-1==0&&j-1==0)
				{
					dp[i][j]=in[i-1][j-1];
					continue;
				}
				int a1=dp[i-1][j];
				int a2=dp[i-1][j-1];
				int a3=dp[i][j-1];
				dp[i][j]=in[i-1][j-1]+min(a1,min(a2,a3));
			}
		}
		return dp[m][n];
}
int main()
{
	int m,n;
	cin>>m>>n;
	int **in=new int *[m];
	for (int i = 0; i < m; ++i)
	{
		in[i]=new int[n];
	}
	for (int i = 0; i < m; ++i)
	{
		for(int j=0;j<n;j++)
		{
			cin>>in[i][j];
		}
	}
	cout<<min_cost(in,m,n)<<endl;//MEMOISATION
	cout<<min_cost1(in,m,n)<<endl;//RECURSIVE
	cout<<min_costs(in,m,n)<<endl;//TOP DOWN
	cout<<min_cost2(in,m,n);//BOTTOM APPROACH
}