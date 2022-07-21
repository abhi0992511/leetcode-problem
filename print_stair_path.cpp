#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
void Path_stair(int n,string Path)
{
	if (n<0)
	{
		return;
	}
	if (n==0)
	{
		cout<<Path<<" ";
		return;

	}
	Path_stair(n-1,Path+"1");
	Path_stair(n-2,Path+"2");
	Path_stair(n-3,Path+"3");
	return;
}
int main()
{
	int n;
	cin>>n;
	Path_stair(n,"");
}