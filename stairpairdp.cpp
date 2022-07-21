#include <bits/stdc++.h>
using namespace std;
int step(int n)
{ int m[n+1];
m[0]=1;m[1]=1;
m[2]=2;
for (int i = 3; i <=n; i++)
{
	m[i]=m[i-3]+m[i-2]+m[i-1];
}
return m[n];
}
int main()
{
	int n;
	cout<<"enter the no of step";
	cin>>n;
	int s=step(n);
	cout<<s;
}