#include<bits/stdc++.h>
using namespace std;
double geo(int n)
{
	if(n==0)
	{
		return 1;
	}
	double ans=1/(double)pow(2,n)+geo(n-1);
	return ans;
}
int main()
{
	int n;
	cout<<"enter ano";
	double ans=geo(n);
	cout<<ans;
}