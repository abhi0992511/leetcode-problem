#include <bits/stdc++.h>
using namespace std;
int total_way(int n,int oc,int cc,int total)
{
	if (oc>n||cc>n)
	{
		return 0;
	}
	if (oc==n&&cc==n)
	{
		return 1;
	}
	if (oc==cc)
	{
		return total_way(n,oc+1,cc,total);
	}
	else if (oc==n)
	{
		return total_way(n,oc,cc+1,total);
	}
	else{
		return total_way(n,oc,cc+1,total)+total_way(n,oc+1,cc,total);
	}
}
int main()
{
	int n;
	cin>>n;
	cout<<total_way(n,0,0,2*n);
}