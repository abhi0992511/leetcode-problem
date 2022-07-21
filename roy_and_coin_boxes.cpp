#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *ans=new int[n+1];
	int *atleast=new int[n+1];
	int *newans=new int[n+1];
	int *strat=new int[n+1];
	int *end=new int[n+1];
	for(int i=0;i<n+1;i++)
	{
		strat[i]=0;
		end[i]=0;
		ans[i]=0;
		newans[i]=0;
		atleast[i]=0;
	}
	int k;
	cin>>k;
	strat[0]=0;
	end[0]=0;
	while(k--)
	{
		int l,r;
		cin>>l>>r;
		strat[l]++;
		end[r]++;
	}
	for(int i=0;i<n+1;i++)
		{
			cout<<strat[i]<<" ";
		}
		cout<<endl;

	for (int i = 0; i<n+1;i++)
	{
	   cout<<end[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<n+1;i++)
	{
       ans[i]=strat[i]-end[i-1]+ans[i-1];
	}
	for (int i = 0; i <n+1; i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<n+1;i++)
		newans[ans[i]]++;
	for (int i = 0; i < n+1; ++i)
	{
		cout<<newans[i]<<" ";
	}
	for(int i=n-1;i>=1;i--)
	{
      newans[i]=newans[i]+newans[i+1];
	}
	cout<<endl;
	for (int i = 0; i <n+1; ++i)
	{
	cout<<newans[i]<<" ";
	
}
