#include <bits/stdc++.h>
using namespace std;
#include<queue>
#include <vector>

void ksortedarray(vector<int>&ans,int k)
{
	priority_queue<int>pq;
	for (int i = 0; i < k; ++i)
	{
		pq.push(ans[i]);
	}
	int j=0;
	for(int i=k;i<ans.size();i++)
	{
		ans[j]=pq.top();
		pq.pop();
		pq.push(ans[i]);
		j++;
	}
	while(!pq.empty())
	{
		ans[j]=pq.top();
		pq.pop();
		j++;
	}
}

int main()
{ 
	int n;
cin>>n;
vector<int>ans(n);

for (int i = 0; i <ans.size(); ++i)
{
   cin>>ans[i];
}
int k;
cin>>k;
ksortedarray(ans,k);
for (int i = 0; i < ans.size(); ++i)
{
	cout<<ans[i]<<" ";
}


}