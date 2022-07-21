#include<bits/stdc++.h>
using namespace std;
//USING DP:
int min_count(int n)
{
   int *a=new int[n+1];
   if (n<=3)
   {
   	return n;
   }
   a[0]=0;
   a[1]=1;
   a[2]=2;
   a[3]=3;
   for (int i = 4; i <n+1 ; i++)
   {
   	a[i]=i;
   	for (int j = 1; j <= ceil(sqrt(n)); j++)
   	{
   		int temp=j*j;
   		if (temp>i)
   		{
   			break;
   		}
   		else
   			a[i]=min(a[i],1+a[i-temp]);

   	}
   	
   }
   return a[n];
}
//USING_RECURSION:
int min_count2(int n)
{
	if (n<=3)
	{
	  return n;
	}
	if(sqrt(n)-floor(sqrt(n))==0)
		return 1;
	int res=n;
	for (int i = 1; i < n+1; ++i)
	{
		int temp=i*i;
		if (temp>n)
		{
			break;
		}
		res=min(res,1+min_count2(n-temp));
	}
	return res;
}
//USING_MEMOISATION:
int min_count3(int n)
{
	vector<int>dp(n+1,-1);
	dp[0]=0;
	dp[1]=1;
	for (int i = 2; i <n+1; ++i)
	{  
		dp[i]=INT_MAX;
		for (int j = 0; i-j*j >=0 ; ++j)
		{
			dp[i]=min(dp[i],dp[i-j*j]);

		}
		dp[i]+=1;
		
	}
	return dp[n];

}
int main()
{
	int n;
	cin>>n;
	cout<<min_count3(n);
	
}