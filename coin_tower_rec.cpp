#include <bits/stdc++.h>
using namespace  std;
bool coin_rec(int n,int x,int y)
{
	if (n==1)
	{
		return true;
	}
	if(n-x==0)
		return true;
	if (n-y==0)
	{
	 return true;
	}
	bool a=coin_rec(n-1,x,y)||coin_rec(n-y,x,y)||coin_rec(n-x,x,y);
	if (a==true)
	{
		return true;
	}
	else
		return false;
}
int main()
{
	int n,x,y;
	cin>>n>>x>>y;
	bool a=coin_rec(n,x,y);
	if(a==true)
		cout<<"A";
	else
		cout<<"B";
}