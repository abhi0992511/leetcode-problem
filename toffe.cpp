#include<bits/stdc++.h>
#include <array>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	int temp=0;
	cin>>n;
	int k;
	cin>>k;
	int *a=new int [n];
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<=n-k;i++)
	{
		temp=a[i];
	}
	cout<<temp;
}