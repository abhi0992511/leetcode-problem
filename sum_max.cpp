#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int sum=0,temp=INT_MIN,s=0,l=0;
	int *a=new int [n];
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	for (int i = 0; i <n-1; i++)
	{
		if (a[i]<a[i+1])
		{
			if (s==0)
			{
				
				sum=sum+a[i]+a[i+1];
				s=1;
			}
			else
			{
				sum=sum+a[i+1];
				if (sum>temp)
				{
					temp=sum;
				}
			}
		}
		else
		{
			s=0;
			l=0;
			sum=0;
		}
	}
	cout<<temp;

}