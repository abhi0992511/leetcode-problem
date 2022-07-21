#include <bits/stdc++.h>
#include <vector>
using namespace std;
void min_row(vector<vector<int>>&matrix,int l,int r,int n,int m)
{
  int dp[n][m];
  for(int i=0;i<m;i++)
  	dp[0][i]=1;
  for(int i=1;i<n;i++)
  {
  	for(int j=0;j<m;j++)
  	{
  		if(matrix[i-1][j]<=matrix[i][j])
  			dp[i][j]=dp[i-1][j];
  		else
  			dp[i][j]=i+1;
  	}
  }
  vector<int>ans;
  int res=INT_MAX;
  for(int i=0;i<n;i++)
  	{
  		for(int j=0;j<m;j++)
  		{
  			res=min(res,dp[i][j]);
  		}
  	  ans.push_back(res);
  	    res=INT_MAX;
  	}
  	if(ans[r]<=l)
  		cout<<"Yes"<<endl;
  	   else
  	   	cout<<"No"<<endl;
  

}
int main()
{
	int n,m;
	cin>>m>>n;
	vector<vector<int>>matrix(n,vector<int>(m));
	  for(int i=0;i<n;i++)
	  {
	  	for(int j=0;j<m;j++)
	  		cin>>matrix[i][j];
	  }
	  int k;
	  cin>>k;
	  int l,r;
	  while(k--)
	  {
    cin>>l>>r;
     min_row(matrix,l,r,n,m);
	  }
}