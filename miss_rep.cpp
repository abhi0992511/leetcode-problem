#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int ans[2];
	unordered_map<int,int>mp;
	for(int i=0;i<n;i++)
		mp[a[i]]++;
	  for(int i=0;i<n;i++)
	  {
	  	if(mp[i]>1)
	  		ans[0]=i;
	  	if(mp[i]==0)
	  		ans[1]=i;
	  }
	
	cout<<ans[0]<<" "<<ans[1];


}