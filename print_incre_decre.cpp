#include <bits/stdc++.h>
using namespace std;
void print_inc_dec(int n)
{
	if (n<0)
	{ 
		cout<<endl;
		return;
	}
	cout<<n<<" ";
	print_inc_dec(n-1);
	cout<<n<<" ";
}
int main()
{
	int n;
	cin>>n;
	print_inc_dec(n);
}