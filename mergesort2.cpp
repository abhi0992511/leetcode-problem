#include <bits/stdc++.h>
using namespace std;
void merge(int *a,int l,int r,int mid)
{
	int ls=mid-l+1;
	int la[ls+1];
	int rs=r-mid;
	int ra[rs+1];
	for(int i=0;i<ls;i++)
	{
		la[i]=a[i+l];
	}
	for(int i=0;i<rs;i++)
	{
		ra[i]=a[i+mid+1];
	}
	la[ls]=ra[rs]=INT_MAX;
	int li=0;
	int ri=0;
	for(int i=l;i<=r;i++)
	{
		if(la[li]<=ra[ri])
		{
			a[i]=la[li];
			li++;
		}
		else
		{
			a[i]=ra[ri];
			ri++;
		}
	}
}
void merge_sort(int *a,int l,int r)
{ 
	 if(l==r)
	 	return ;
   int mid=  l+(r-l)/2;
     merge_sort(a,l,mid);
     merge_sort(a,mid+1,r);
     merge(a,l,r,mid);
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
	merge_sort(a,0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" " ;
}