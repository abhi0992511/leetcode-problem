#include <bits/stdc++.h>
using namespace std;
//USING_MEMOISATION:
long long int factorial(long long int n,long long int *a)
{

	if(n==0||n==1)
	{
		return 1;
	}
	if(a[n]!=-1)
	{
		return a[n];
	}
	a[n]=n*factorial(n-1,a);
	return a[n];


}
int main()
{
	long long int n;
	cin>>n;
   long long int *a=new long long int [n+1];
	for (int i = 0; i < n+1; ++i)
	{
		a[i]=-1;
	}
	cout<< factorial(n,a);
}