#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a[100];
	int n;
	cout<<"enter the size";
	// int * a=new int [n];
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for (int i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
}
