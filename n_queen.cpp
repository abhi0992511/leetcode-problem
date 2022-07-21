#include <bits/stdc++.h>
#include <string>
using namespace std;
bool is_safe(vector<vector<int>>a,int row,int col)
{
	for (int i =row-1,j=col;i>=0;i--)
	{
		if (a[i][j]==1)
		{
			return false;
		}
	}
	for (int i =row-1,j=col-1;i>=0&&j>=0 ;i--,j--)
	{
			if (a[i][j]==1)
		{
			return false;
		}
	}
	for (int i =row-1,j=col+1;i>=0&&j<a.size();i--,j++)
	{
			if (a[i][j]==1)
		{
			return false;
		}
	}
	return true;
}
void n_path(vector<vector<int>>a,string path,int index)
{
	if(index==a.size())
	{
		cout<<path<<" ";
		return;
	}
	for(int col=0;col<a.size();col++)
	{   if(is_safe(a,index,col)==true)
		{
			a[index][col]=1;
		n_path(a,path+to_string(index)+"-"+to_string(col)+",",index+1);
		a[index][col]=0;
		}
	}
	return;
}
int main()
{
	int n;
	cin>>n;
	vector<vector<int>>a(n,vector<int>(n));
	n_path(a,"",0);
}