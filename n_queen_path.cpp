#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
void path_n_queen(vector<string>&chess,bool *col,bool *dia,bool *antidia,int row,vector<vector<string>>&ans,int n)
{
	if (row==n)
	{
		ans.push_back(chess);
		return;
	}
	for (int coll=0;coll<chess.size();coll++)
	{
		if (col[coll]==false&&dia[row+coll]==false&&antidia[row-coll+chess.size()-1]==false)
		{
			chess[row][coll]='Q';
			col[coll]=true;
			dia[row+coll]=true;
			antidia[row-coll+chess.size()-1]=true;
			path_n_queen(chess,col,dia,antidia,row+1,ans,n);
			chess[row][coll]='.';
			col[coll]=false;
			dia[row+coll]=false;
			antidia[row-coll+chess.size()-1]=false;

		}
	}
}
int main()
{
	int n;
	cin>>n;
	vector<string>chess(n,string(n,'.'));
	bool col[n];
	bool dia[2*n-1];
	bool antidia[2*n-1];
	vector<vector<string>>ans;
	path_n_queen(chess,col,dia,antidia,0,ans,n);
	for (int i =0;i<ans.size(); ++i)
	{
	  for(int j=0;j<ans[0].size();j++)
	  	cout<<ans[i][j]<<" ";
	  cout<<endl;
	}
}