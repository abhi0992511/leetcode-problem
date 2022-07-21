#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int step=0;
	while(n>0)
	{
		if(n%2!=0)
		{
			n=n-1;
			
		}
		else
		{
		 	n=n/2;
		}
		step++;
	}
	cout<<step;
}