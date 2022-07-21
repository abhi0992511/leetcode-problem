#include <bits/stdc++.h>
using namespace std;
int maximum(int *a,int i,int n)
{
	if(i==n)
		return a[i];
	return max(a[i],maximum(a,i+1,n));
}
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<maximum(a,0,n-1);
}