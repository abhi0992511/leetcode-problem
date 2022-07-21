#include <bits/stdc++.h>
#include <vector>
using namespace std;
int find_row(vector<vector<int>>&matrix,int x)
{ 
	int h=matrix.size()-1;
	int l=0;
	int c=matrix[0].size()-1;

	while(l<=h)
	{
		int mid=l+(h-l)/2;
		if(matrix[mid][c]>=x&&x>=matrix[mid][0])
		{
		    return mid;
		}
		else if(matrix[mid][0]<x)
			l=mid+1;
		else if(matrix[mid][0]>x)
			h=mid-1;
	}
	return -1;
}
bool search(vector<vector<int>>&matrix,int x,int row)
{
	
int low=0;
int high=matrix[0].size()-1;
while(low<=high)
{
	int mid=low+(high-low)/2;
	if(matrix[row][mid]==x)
		return true;
	else if (matrix[row][mid]>x)
	{
		high=mid-1;
	}
	else if(matrix[row][mid]<x)
		low=mid+1;
}
return false;

}
int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>>matrix(n,vector<int>(m));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>matrix[i][j];
		}
	}
	int x;
	cin>>x;
	int row=find_row(matrix,x);
	//cout<<x;
	if(row==-1)
		cout<<"NOT_FOUND";
	else
		cout<<search(matrix,x,row);

}