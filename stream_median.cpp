#include <bits/stdc++.h>
#include<vector>
#include <algorithm>
using namespace std;
void median(int *a,int n)
{
	int i=0;
	priority_queue<int>p;
	while(i<n)
	{
         // p.push(a[i]);
         // if (i%2==0)
         // {
         // 	for (int j = 0; j<i; j++)
         // 	{
         		
         // 	}
         // }
		sort(a,a+i+1);
			if (i%2!=0)
			{
				cout<<a[i/2]<<" ";
			}
			else
			{
				int x=(a[i/2]+a[i/2+1])/2;
				cout<<x<<" ";
			}
		



		i++;

	}
}
int main()
{

int n;
cin>>n;
int *a=new int[n];
for(int i=0;i<n;i++)
{
	cin>>a[i];
}
median(a,n);





}