#include<bits/stdc++.h>
#include <vector>
//#include <unordered_map>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int>v(n);
	for (int i = 0; i < v.size(); i++)
	{
		cin>>v[i];
	}
	//sort(v.begin(),v.end());
	int sum=0;
	int count=0;
	for (int i = 0; i < v.size()-1; i++)
	{
		// sum=sum+v[i];
		// count++;
		// if(sum==0)
		// {
  //           break;
		// }
		for (int j = 1; j < v.size(); j++)
		{
			sum=sum+v[i]+v[j];
			count++;
			if (sum==0)
			{
				break;

			}
		}
		count=0;
	}
	cout<<count;
}