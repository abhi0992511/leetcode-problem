#include <bits/stdc++.h>
using namespace std;
void all_index(int *a,int n,int k,int i)
{
	if(i==n)
		return ;
	if(a[i]==k)
		cout<<i<<" " ;
	 all_index(a,n,k,i+1);
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
	int k;
	cin>>k;
	all_index(a,n,k,0);
}