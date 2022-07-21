#include <bits/stdc++.h>
using namespace std;
 int main()
{
	int n;
	cin>>n;
	int ans=0;
	int temp=INT_MIN;
	int *a=new int [n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for (int i = 0; i <n-1; i++)
	{    ans=a[i];
		if (a[i]<a[i+1])
		{
			ans=ans+a[i+1];
			if(ans>temp)
			{
				temp=ans;
			}
		}
		else{
			ans=0;
		
		}

	}
	cout<<temp;
}
