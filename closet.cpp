#include<bits/stdc++.h>
#include <climits>
using namespace std;

int main()
{
	int n;
	int ans=INT_MAX;
	cin>>n;
	int *a=new int [n];
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if(abs(a[i]-a[j])<ans)
			{
               ans=abs(a[i]-a[j]);
			}
		}
	}
	cout<<ans;

}