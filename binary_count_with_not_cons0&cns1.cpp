#include <bits/stdc++.h>
using namespace std;
//USING_DP:(USING_EXTRA_SPACE)
int count(int n)
{
	int *dp0=new int [n+1];
	int *dp1=new int [n+1];
	dp0[0]=0;
	dp1[0]=0;
	dp0[1]=1;
	dp1[1]=1;
	for (int i = 2; i < n+1; i++)
	{
	dp1[i]=dp1[i-1]+dp0[i-1];
	dp0[i]=dp1[i-1];
	}
	return dp1[n]+dp0[n];
}
//ITREATIVE(WITHOUT_EXTRA_SPACE)
int count1(int n)
{
	int o0=1;
	int o1=1;
	for (int i = 2; i < n+1; ++i)
	{
		int n0=o1;
		int n1=o1+o0;
		o1=n1;
		o0=n0;
	}
	return o1+o0;

}


int main()
{
	int n;
	cin>>n;
	cout<<count1(n);

}