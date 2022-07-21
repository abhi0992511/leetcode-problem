#include<bits/stdc++.h>
using namespace std;
int gp(int n,int a,int r)
{
	 int pow=1;
    for(int i=1;i<n;i++)
    {
        pow=pow*r;
    }
    return a*pow;
}

int main()
{
	int n,a,r;
	cin>>n>>a>>r;
	int x=gp(n,a,r);
	cout<<x;
}