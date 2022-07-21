#include <bits/stdc++.h>
using namespace std;
//USING_RECURSION:
int alpha(int*a,int n)
{
	if (n==1)
	{
		return 1;

	}
	if (n==0)
	{
		return 1;
	}
	int output=alpha(a,n-1);
	if (a[n-2]*10+a[n-1]<=26)
	{
		output+=alpha(a,n-2);
	}
	return output;
}
//USING_MEMOSIATION:
int alpha2(int *a,int n,int *ans)
{
	if (n==1)
	{
		return 1;
	}
	if (n==0)
	{
		return 1;
	}
	if (ans[n]!=0)
	{
		return ans[n];
	}
	int output=alpha2(a,n-1,ans);
	if (a[n-2]*10+a[n-1]<=26)
	{
		output+=alpha2(a,n-2,ans);
	}
	ans[n]=output;
	return output;
}
//USING_DP:
int alpha3(int *a,int n)
{

	int *ans=new int[n+1];
	ans[0]=1;
	ans[1]=1;
	for (int i = 2; i <n+1 ; ++i)
	{
		ans[i]=ans[i-1];
		if (a[i-2]*10+a[i-1]<=26)
		{
		ans[i]+=ans[i-2];
		}
	}
	return ans[n];
}
int main()
{
	int n;
	cin>>n;
	int *a= new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int *ans=new int[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		ans[i]=0;
	}
	cout<<alpha3(a,n);
}