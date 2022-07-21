#include <bits/stdc++.h>
using namespace  std;
int power(int n,int x)
{
	if(x==0)
		return 1;
	return n*power(n,x-1);
}
long long power1(int n,int x)
{
	if (x==0)
	{
		return 1;
	}
	long long xn=power1(n,x/2);
	 xn=xn*xn;
	 if(x%2!=0)
	 {
	 	xn=n*xn;
	 }
	 return xn;
}
int main()
{
	int n,x;
	cin>>n>>x;
	cout<<power1(n,x)<<endl;
	cout<<power(n,x);
}