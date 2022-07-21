#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int count=0;
	for(int i=0,j=i+1;i<n;i++)
	{
		if(a[i]>a[j])
		{
			count=count+1;
		}
	}
	cout<<count;
}