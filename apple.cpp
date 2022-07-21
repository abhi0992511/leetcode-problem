#include<bits/stdc++.h>
//#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int total=0;
	int equal=0;
	int x=0;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		total=total+a[i];
	}
	equal=total/n;

	for(int i=0;i<n;i++)
	{
		if(a[i]>=equal)
		{
            x=x+a[i]-equal;
		}
	}
	cout<<x;
	return 0;


}