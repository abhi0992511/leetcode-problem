#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int n;
	cin>>n;
  long long	int *a=new long long int[n+1];
	a[0]=0;
	a[1]=1;
	for (long long int i = 2; i < n+1; i++)
	 {
		a[i]=a[i-1]+a[i-2];

	}
	cout<<a[n];
}