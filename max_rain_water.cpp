#include <bits/stdc++.h>
#include <vector>
using namespace std;
//BRUTE_FORCE:
int max_water(vector<int>&height)
{
	int area=INT_MIN;
	for (int i = 0; i < height.size()-1; ++i)
	{
		for(int j=i+1;j<height.size();j++)
		{
			int high=min(height[i],height[j]);
			area=max(area,high*(j-i));
		}
	}
	return area;
}
//OPTIMAL:
int max_water1(vector<int>&height)
{
	int l=0;
	int h=height.size()-1;
	int area=0;
	while(l<h)
	{
		int high=min(height[l],height[h]);
		area=max(area,high*(h-l));
		if (height[l]<height[h])
		{
			l++;
		}
		else
			h--;
	}
	return area;
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
	cout<<max_water(height)<<endl;
	cout<<max_water1(height);
}