#include <bits/stdc++.h>
using namespace std;
int occurence(int*a,int n,int k,int i)
{
	if (i==n)
	{
		return -1;
	}
	int index=occurence(a,n,k,i+1);
	if(index==-1)
	{
		if(a[i]==k)
			return i;
		else
			return -1;
	}
	else
		return index;
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
	cout<<occurence(a,n,k,0);

}