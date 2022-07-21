#include <bits/stdc++.h>
using namespace std;
void zigzack(int n)
{
	if (n==0)
	{
	return ;
	}
	cout<<n<<" ";
	zigzack(n-1);
	cout<<n<<" ";
	zigzack(n-1);
	cout<<n<<" ";
}
int main()
{
	int n;
	cin>>n;
	zigzack(n);
}