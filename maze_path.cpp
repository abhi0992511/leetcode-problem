#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
vector<string>path(int i,int j,int m,int n)
{
	if (i==m-1&&j==n-1)
	{
		vector<string>empty;
		empty.push_back("");
		return empty;
	}
	vector<string>hpath;
	vector<string>vpath;
	if (i<m)
	{
	hpath=path(i+1,j,m,n);
	}
	if (j<n)
	{
		vpath=path(i,j+1,m,n);
	}
	vector<string>data;
	for (string i:hpath)
	{
		data.push_back("h"+i);
	}
	for (string i:vpath)
	{
		data.push_back("v"+i);
	}
	return data;
}
int main()
{
	int n,m;
	cin>>m>>n;
	vector<string>ans=path(0,0,m,n);
	for (int i = 0; i < ans.size(); ++i)
	{
		cout<<ans[i]<<" ";
	}
}