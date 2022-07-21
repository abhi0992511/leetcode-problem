#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
void flood_fill(vector<vector<int>>a,int m,int n,int i,int j,string path,vector<vector<bool>> visted)
{
	if (i<0||j<0||i>=m||j>=n||a[i][j]==1||visted[i][j]==true)
	{
		return;
	}
	if (i==m-1&&j==n-1)
	{
		cout<<path<<" ";
		return;
	}

	    visted[i][j]=true;
	
		flood_fill(a,m,n,i-1,j,path+"t",visted);
		flood_fill(a,m,n,i,j+1,path+"r",visted);
		flood_fill(a,m,n,i+1,j,path+"d",visted);
		flood_fill(a,m,n,i,j-1,path+"l",visted);
	
          visted[i][j]=false;

}
int main()
{
	int m,n;
	cin>>m>>n;
     vector<vector<int>>a(m,vector<int>(n));
     for(int i=0;i<m;i++)
     {
     	for (int j=0;j<n;j++)
     	{
     		cin>>a[i][j];
     	}
     }
     vector<vector<bool>>visted(m,vector<bool>(n));
     flood_fill(a,m,n,0,0,"",visted);

}