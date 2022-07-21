#include<bits/stdc++.h>
using namespace std;
//USING_DP:
int maximum(int n,int *a)
{
	int *ans=new int [n];
	ans[0]=a[0];
	ans[1]=max(a[0],a[1]);
	for (int i = 2; i < n; i++)
	{
		ans[i]=max(a[i]+ans[i-2],ans[i-1]);
	}
	return ans[n-1];
}
//USING_MEMOISATION:
int maximum2(int i,int n,int *a,int *dp)
{
   
   if(i>=n)
   {
   	return 0;
   }
   if (dp[i]!=-1)
   {
   	return dp[i];
   }
   dp[i]=max(maximum2(i+2,n,a,dp)+a[i],maximum2(i+1,n,a,dp));
   int ans=dp[i];
   return ans;
}
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int *dp=new int [n+1];
	for (int i = 0; i <n+1; ++i)
	{
	    dp[i]=-1;
	}
	cout<<maximum2(0,n,a,dp);
	
}