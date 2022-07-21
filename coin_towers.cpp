#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,y;
	cin>>n>>x>>y;
	bool *ans=new bool[n+1];
	ans[0]=false;
	ans[1]=true;
	for (int i=2; i < n+1; i++)
	{
		if (i-1>=0&&ans[i-1]==false)
		{
			ans[i]=true;
		}
		else if (i-x>=0&&ans[i-x]==false)
		{
			ans[i]=true;
		}
		else if (i-y>=0&&ans[i-y]==false)
		{
			ans[i]=true;
		}
		else
			ans[i]=false;
	}
	if (ans[n]==true)
	{
		cout<<"A";
	}
	else
		cout<<"B";

}