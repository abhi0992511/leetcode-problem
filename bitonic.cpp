#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int>arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
    vector<int>lis(n);
    vector<int>lds(n);
    for(int i=0;i<n;i++)
    {
    	lis[i]=1;
    	for(int j=i-1;j<n;j++)
    	{
    		if(arr[i]>arr[j]&&lis[i]<lis[j]+1)
    			lis[i]=lis[j]+1;
    	}
    }
    for(int i=0;i<n;i++)
    	cout<<lis[i]<<" ";
    cout<<endl;
    for(int i=n-1;i>=0;i--)
    {
    	lds[i]=1;
    	for(int j=i+1;j<n;j++)
    	{
    		if(arr[i]>arr[j]&&lds[i]<lds[j]+1)
    			lds[i]=lds[j]+1;
    	}
    }
    for (int i = 0; i < n; ++i)
    {
    	cout<<lds[i]<<" ";
    }
    cout<<endl;
    int res=0;
    for(int i=0;i<n;i++)
    {
    	res=max(res,lis[i]+lds[i]-1);
    }
    cout<< res;
}