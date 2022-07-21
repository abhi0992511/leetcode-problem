#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
using namespace std;
// void count_pair(vector<int>&v,int k)
// {
// 	sort(v.begin(),v.end());
// 	int i=0,j=v.size(),count=0;
// 	int r=0;
// 	while(i<j)
// 	{
// 		if(v[i]-v[r]==k)
// 		{
// 			count++;
// 			i++;
// 			r++;
// 		}
// 		else if (v[r]-v[i]>k)
// 		{
// 			i++;
// 		}
// 		else
// 		r++;
		

// 	}
// 	cout<<count;
// }

int main()
{
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<v.size();i++)
		cin>>v[i];
	int k;
	cin>>k;
	//count_pair(v,k);
	int count=0;
	unordered_map<int,int>m;
	for (int i = 0; i < v.size(); i++)
	{
	     m[v[i]]++;
	}
	for (int i = 0; i < v.size(); i++)
	{
		int x=v[i];
		if (x-k>=0&&m[x-k])
		{
			m[x-k]--;
			count++;
		}
		// //else(m[x+k])
		// {
  //          m[x+k]--;
  //           count++;
		// }
	}
	cout<<count;


}