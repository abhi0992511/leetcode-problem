#include <bits/stdc++.h>
#include <vector>
using namespace std;
void swap_sort(vector<int>&in,int n)
{
	int i=0;
	while(i<n)
	{
		if(in[i]!=in[in[i]-1])
		{
			swap(in[i],in[in[i]-1]);
		}
		else
		{
			i++;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	vector<int>in(n);
	for(int i=0;i<n;i++)
	{
		cin>>in[i];
	}
	swap_sort(in,n);
	for(int i=0;i<n;i++)
		 cout<<in[i]<<" ";
}