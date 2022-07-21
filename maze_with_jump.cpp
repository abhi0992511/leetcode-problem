#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;
vector<string>path(int i,int j,int m,int n)
{ 

	if(i==m&&j==n)
	{
		vector<string>empty;
		empty.push_back("");
		return empty;
	}
// 	if (i>=m||j>=n)
// {
// 		vector<string>neg;
// 		return neg;
// 	}
	vector<string>ans;
	//horizontal:
	for (int ms=1;ms<=n-j;ms++)
	{
		vector<string>hpath=path(i,j+ms,m,n);
		for (string k:hpath)
		{
			ans.push_back("h"+ms+k);
		}
	}
	//vertical:
	for (int ms=1;ms<=m-i;ms++)
	{
		vector<string>vpath=path(i+ms,j,m,n);
		for (string k:vpath)
		{
			ans.push_back("v"+ms+k);
		}
	}
	//digonal:
	for (int ms=1;ms<=m-j&&ms<=n-i;ms++)
	{
		vector<string>dpath=path(i+ms,j+ms,m,n);
		for (string k:dpath)
		{
			ans.push_back("d"+ms+k);
		}
	}
	return ans;
}
int main()
{
	int m,n;
	cin>>m>>n;
	vector<string>ans=path(1,1,m,n);
	for (int i = 0; i < ans.size(); ++i)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	cout<<ans.size();
}