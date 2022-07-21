#include <bits/stdc++.h>
#include <vector>
using namespace std;
void target_sum_path(vector<int>a,int i,int target,int sum,string output)
{   
	if(i>=a.size())
	{ 
		if (target==sum)
	{
		cout<<output<<" ";
	
	}
		return;
	}
	
	target_sum_path(a,i+1,target,sum+a[i],output+to_string(a[i])+" ");
	target_sum_path(a,i+1,target,sum,output);
	return;
}
int main()
{
	int n;
	cin>>n;
	vector<int>a(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int target;
	cin>>target;
	target_sum_path(a,0,target,0,"");
}