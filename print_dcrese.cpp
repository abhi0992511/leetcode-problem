#include <bits/stdc++.h>
using namespace std;
void print_decrese(int n)
{
	if(n<0)
	{
		return;
	}
	cout<<n<<" ";
	print_decrese(n-1);
}
int main()
{
	int n;
	cin>>n;
	print_decrese(n);
}