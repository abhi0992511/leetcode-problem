#include <bits/stdc++.h>
using namespace std;
unsigned long int dp[100001];
//RECURSIVE:
unsigned long int catlan_num1(int n)
{
	if(n<=1)
		return 1;
  unsigned long	int res=0;
	for(int i=0;i<n;i++)
		res+=catlan_num1(i)*catlan_num1(n-i-1);
	return res;
}
//RECURISIVE+MEMOISED:
unsigned long int catlan_num(int n)
{
   if (n<=1)
   {
   	return 1;
   }
   if(dp[n]!=-1)
   	return dp[n];
  unsigned long int res=0;
   for(int i=0;i<n;i++)
   	  {
   	  	res+=catlan_num(i)*catlan_num(n-i-1);
   	  }
   	  dp[n]=res;
   	return dp[n];

}
//DP:
unsigned  int catlan_num2(int n)
{
	vector<unsigned int>dp(n+1);
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		for (int j=0;j<i;j++)
		{
		dp[i]+=dp[j]*dp[i-j-1];
		}
	}
	return dp[n];
}
int main()
{
	int n;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	cout<<catlan_num2(n)<<endl;
	cout<<catlan_num(n)<<endl;
	cout<<catlan_num1(n);
}