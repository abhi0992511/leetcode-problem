#include <bits/stdc++.h>
#include <vector>
using namespace std;
int rain_water(vector<int>&height)
{
	int n=height.size();
	vector<int>right(n);
	vector<int>left(n);
	right[n-1]=height[n-1];
	left[0]=height[0];
	for (int i = 1; i < n; ++i)
	{
	left[i]=max(left[i-1],height[i]);

	}
	for(int i=n-2;i>=0;i--)
	{
		right[i]=max(right[i+1],height[i]);
	}
	vector<int>ans(n);
	for (int i = 0; i < n; ++i)
	{
		ans[i]=min(right[i],left[i])-height[i];
	}
	int res=0;
	for(int i=0;i<n;i++)
	{
		res=res+ans[i];
	}
	return res;
}
int main()
{
	int n;
	cin>>n;
	vector<int>height(n);
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin>>x;
		height.push_back(x);
	}
	cout<<rain_water(height);
}