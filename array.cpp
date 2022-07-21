#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int*arr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int *newarray=new int [n];
	for (int i = 0; i < n; i++)
	{
		newarray[i]=0;
	}
	int count=0;
	for (int i = 0; i < n; i++)
	{ 
		
		if (arr[i]%10==0)
		{ 
			count++;
			
		}
	
	}
	//cout<<count<<endl;
	int j=0;
	for (int i = 0; i <n; i++)
	{
		if (arr[i]%10!=0)
		{
			
			newarray[j]=arr[i];
			j++;
		}
		
	}
	for (int i = 0; i <n; i++)
	{
		if (arr[i]%10==0)
		{
			newarray[j]=arr[i];
			j++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout<<newarray[i]<<" ";
	}


}