#include<bits/stdc++.h>
using namespace std;
string player(int n,int x,int y)
{
	bool *a=new bool [n+1];
	a[0]=false;
	a[1]=true;
	for (int i = 2; i < n+1; ++i)
	{
		if(i-1>=0&&a[i-1]==false)
		{
			a[i]=true;
		}
		else if (i-x>=0&&a[i-x]==false)
		{
			a[i]=true;
		}
		else if (i-y>=0&&a[i-y]==false)
		{
			a[i]=true;
		}
		else
			a[i]=false;
	}
	if (a[n]==true)
	{
		return "A";
	}
	else
		return "B"; 

}
int main()
{
	int n,x,y;
	cin>>n>>x>>y;
	cout<<player(n,x,y);

}