#include <bits/stdc++.h>
using namespace std;
int count_bst(int n)
{
	if (n<=1)
	{
	  return 1;
	}
	int tem=0;
	for(int i=1;i<=n;i++)
	{
		 tem+=count_bst(i-1)*count_bst(n-i);
	}
	return tem;
}
int main()
{
	int n;
	cin>>n;
	cout<<count_bst(n);
}