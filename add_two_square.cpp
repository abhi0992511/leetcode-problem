#include <bits/stdc++.h>
using namespace std;
bool add_two_square(int n)
{
	for(int i=0;i<=floor(sqrt(n));i++)
	{
		for(int j=i;j<=floor(sqrt(n));j++)
		{
			if (i*i+j*j==n)
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int n;
	cin>>n;
	cout<<add_two_square(n);
}