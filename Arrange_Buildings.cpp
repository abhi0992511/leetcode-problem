#include <bits/stdc++.h>
using namespace std;
//ITREATIVE(WITHOUT_EXTRA_SPACE)
int count(int n)
{
	int ob=1;
	int os=1;
	for (int i = 2; i < n+1; ++i)
	{
		int nb=os;
		int ns=os+ob;
		os=ns;
		ob=nb;

	}
	int total=os+ob;
	total=total*total;
	return total;
}
//USING_DP(WITH_EXTRA_SPACE)
long long count1(int n)
{
	long long*dpb=new long long [n+1];
	long long *dps=new long long [n+1];
	dps[0]=0;
	dps[1]=1;
	dpb[0]=0;
	dpb[1]=1;
	for (int i = 2; i < n+1; ++i)
	{
		dpb[i]=dps[i-1];
		dps[i]=dps[i-1]+dpb[i-1];
	}
	long long total=dps[n]+dpb[n];
	total=total*total;
	return total;
}
int main()
{
	int n;
	cin>>n;
	cout<<count1(n);
}