#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
vector<string>path(int n)
{
	if(n==0)
	{
		vector<string>empty;
		empty.push_back("");
		return empty;
	}
	else if(n<0)
	{
		vector<string>neg;
		return neg;
	}
	vector<string>path1=path(n-1);
	vector<string>path2=path(n-2);
	vector<string>path3=path(n-3);
	vector<string>fullpath;
	for(string i:path1)
	{
		fullpath.push_back("1"+i);
	}
	for(string i:path2)
	{
		fullpath.push_back("2"+i);
	}
	for(string i:path3)
	{
		fullpath.push_back("3"+i);
	}
	return fullpath;

}
int main()
{
	int s;
	cin>>s;
	vector<string>ans=path(s);
	for (int i = 0; i < ans.size(); i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl; 
	cout<<ans.size();
}