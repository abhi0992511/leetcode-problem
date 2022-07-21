#include <bits/stdc++.h>
using namespace std;
int fab_helper(int n,int *a)
{
	if (n<=1)
	{
		return n;
	}
	if (a[n]!=-1)
	{
		return a[n];
	}
	int x=fab_helper(n-1,a);
	int b=fab_helper(n-2,a);
	a[n]=x+b;
	return a[n];
}
int fab(int n)
{
	int *a=new int[n+1];
    for (int i = 0; i < n+1; i++)
    {
       a[i]=-1;
    }
     return fab_helper(n,a);





	}
int main()
{
	int n;
	cin>>n;
	cout<<fab(n);
}