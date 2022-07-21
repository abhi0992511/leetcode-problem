#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int nCr(int n,int r)
{
        
         if(r>n)
        return 0;
        if(n==0||r==0)
        return 1;
        return ((nCr(n-1,r-1))%mod+(nCr(n-1,r))%mod)%mod;
        
}
int main()
{
	int n,r;
	cin>>n>>r;
	cout<<nCr(n,r);
}