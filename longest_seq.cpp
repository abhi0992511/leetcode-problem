#include<bits/stdc++.h>
#include<vector>
#include <unordered_map>
using namespace std;
void subsequence(vector<int>&v)
{
	unordered_map<int,bool>m;
	for (int i = 0; i < v.size(); i++)
	{
	  m[v[i]]=true;
	}
	int count=0;
	int maxcout=0;
	int start=0;
	int x;
	for (int i = 0; i < v.size(); i++)
	{
		int x=v[i];
		if (m.find(x-1)==m.end())
		{
			int a=v[i]+1;
			count=1;
			while(m.find(a)!=m.end())
			{
				count++;
				a++;
				x=v[i];
				if(start<x)
				{
					start=x;
				}
			}
			if(count>maxcout)
			{
			maxcout=max(maxcout,count);
             start=x;	
			}
			
		}
	}
	cout<<start<<" "<<maxcout+start-1;
}
int main()
{ 
	int n;
	cin>>n;
vector<int>v(n);
for (int i = 0; i <v.size(); i++)
{
	cin>>v[i];
}
subsequence(v);

}