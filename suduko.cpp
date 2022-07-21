#include <bits/stdc++.h>
#include<vector>
using namespace std;
bool isvalid(vector<vector<int>>suduko,int i,int j,int val)
{
	for (int col=0;col<suduko[0].size();col++)
	{
		if (suduko[i][col]==val)
		{
			return false;
		}
	}

	for (int row=0;row<suduko.size();row++)
	{
		if (suduko[row][j]==val)
		{
			return false;
		}
	}
	int nrw=3+i/3;
	int nc=3+j/3;
	for(int nr=0;nr<3;nr++)
	{
		for(int ncr=0;ncr<3;ncr++)
		{
			if(suduko[nr][ncr]==val)
				return false;
		}
	}
	return true;
}
bool help(vector<vector<int>>&suduko,int i ,int j)
{
	if(i>=suduko.size())
	{
		return true;;
	}
	int ni=0;
	int nj=0;
	if(j==suduko[0].size()-1)
	{
		ni=i+1;
		nj=0;
	}
	else
	{
		ni=i;
		nj=j+1;
	}
	if (suduko[i][j]!=0)
	{
	 return help(suduko,ni,nj);
	}
	{
		for (int val=1;val<=9;val++)
		{
			if(isvalid(suduko,i,j,val)==true)
			{
				suduko[i][j]=val;
				if(help(suduko,ni,nj)==true)
					return true;
				else
				suduko[i][j]=0;
			}
		}
	}
	return false;
}
int main()
{
	vector<vector<int>>suduko(9,vector<int>(9));
	for (int i = 0; i <9; ++i)
	{
		for(int j=0;j<9;j++)
		{
			cin>>suduko[i][j];
		}
	}
	help(suduko,0,0);
	for (int i = 0; i <9; ++i)
	{
		for(int j=0;j<9;j++)
		{
		cout<<suduko[i][j]<<" ";
		}
	}
	
}