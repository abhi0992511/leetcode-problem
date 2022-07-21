#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int maximum_freuquncy(int*a,int size)
{
  unordered_map<int,int>freq;
  for(int i=0;i<size;i++)
  {
  	freq[a[i]]++;
  }
  int max=0;
  int num=-1;
  for (auto i:freq)
  {
  	if (max<i.second)
  	{
  		num=i.first;
  		max=i.second;
  	}
  }
  return num;
}
int main()
{
	int n;
	cin>>n;
	int *a=new int [n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<maximum_freuquncy(a,n);
}