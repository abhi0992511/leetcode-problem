#include <bits/stdc++.h>
using namespace std;
int no_rotation(int a[],int n)
{
	int i=0,j=n-1;
	while(i<=j)
	{
		int mid=i+(j-i)/2;
		if(a[mid-1]>=a[mid]&&a[mid+1]>=a[mid])
		{
			return mid;
		}
		else if(mid>0&&a[mid-1]>a[mid]&&a[i]>a[mid])
			i=mid+1;
		else
			i=mid-1;
	}
	return -1;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<no_rotation(a,n);
}