#include <bits/stdc++.h>
using namespace std;
bool diff_two_square(int n)
{
	for(int i=0;i<=ceil(sqrt(n));i++)
	{
		for(int j=1;j<=ceil(sqrt(n));j++)
		{
			if (abs(i*i-j*j==n))
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
	cout<<diff_two_square(n);
}