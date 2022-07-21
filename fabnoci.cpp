#include<bits/stdc++.h>

using namespace std;
int fab(int n)
{
	if(n==0)
	{
		return 0;

	}
	if(n==1)
	{
		return 1;

	}
	int fab1=fab(n-1);
	int fab2=fab(n-2);
	return fab1+fab2;
}

int main()
{
	int n;
	cout<<"Enter the fabnoci no"<<endl;
	cin>>n;
	int f=fab(n);
	cout<<f;
}
