#include <bits/stdc++.h>
using namespace std;
int min_cost(int **arr,int n,int m,int i,int j)
{
   if(i>=n||j>=m||j<0||i<0)
   	  return INT_MAX;
   	if (i==m-1&&j==n-1)
   	{
   		return arr[i][j];
   	}
   	int x=min_cost(arr,n,m,i+1,j+1);
   	int y=min_cost(arr,n,m,i+1,j);
   	int z=min_cost(arr,n,m,i+1,j-1);
   	int ans=min(x,min(y,z))+arr[i][j];
   	return ans;
}
int main()
{
	int m,n;
	cin>>m>>n;
	int **arr=new int *[n];
	for(int i=0;i<n;i++)
		arr[i]=new int [m];
	for (int i = 0; i < n; ++i)
	{
		for(int j=0;j<m;j++)
			cin>>arr[i][j];
	}
	cout<<min_cost(arr,n,m,0,0);
}