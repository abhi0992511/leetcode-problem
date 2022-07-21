#include <bits/stdc++.h>
#include <vector>
#include <set>
using namespace std;
int lcs(vector<int>&a,vector<int>&b,int m,int n)
{
	if(m==0||n==0)
		return 0;
	if(a[m-1]==b[n-1])
	{
		return 1+lcs(a,b,m-1,n-1);
	}
	else
	{
		return max(lcs(a,b,m-1,n),lcs(a,b,m,n-1));
	}
}
int main()
{
	int n;
	cin>>n;
	vector<int>a;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	vector<int>b(a);
	sort(b.begin(),b.end());
	for(int i=0;i<b.size();i++)
		cout<<b[i]<<" ";
	int m=a.size();
	int t=b.size();
	cout<<endl;
	cout<<lcs(a,b,m,t);
}