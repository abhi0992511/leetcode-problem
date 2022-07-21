#include <bits/stdc++.h>
using namespace std;
int partion(int n,int k)
{
	if (n==0||k==0||n<k||n<0)
	{
		return 0;
	}
	if (n==1||k==n)
	{
		return 1;
	}
	return k*partion(n-1,k)+partion(n-1,k-1);
}
int main()
{
	int n,k;
	cin>>n>>k;
	cout<<partion(n,k);
}