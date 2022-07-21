#include <bits/stdc++.h>
using namespace std;
//sieve of eratosthenes algo:
int no_prime(int n)
{
   vector<bool>dp(n+1,true);
   dp[0]=false;
   dp[1]=false;
   for (int i = 2; i*i<=n; ++i)
   {
   	for(int j=2*i;j<=n;j=j+i)
   		dp[j]=false;
   }
   int count=0;
   for (int i = 0; i <n; ++i)
   {
   	if (dp[i]==true)
   	{
   	  count++;
   	}
   }
   return count;
}
int main()
{
	int n;
	cin>>n;
	cout<<no_prime(n);
}