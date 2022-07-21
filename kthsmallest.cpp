#include <bits/stdc++.h>
using namespace std;
#include <queue>
#include <vector>
int main()
{
	int n;
	cin>>n;
	vector<int>ans(n);
	for (int i = 0; i < ans.size(); ++i)
	{
		cin>>ans[i];
	}
	// sort(ans.begin(),ans.end());
	// int k;
	// cin>>k;
	// for (int i = k-1; i >=0; i--)
	// {
	// 	cout<<ans[i]<<" ";
	// }
	priority_queue<int>p;
	for (int i = 0; i < ans.size(); ++i)
	{
		p.push(ans[i]);
	}
	int k;
	cin>>k;
	while(k)
	{
		cout<<p.top()<<endl;
		p.pop();
		k--;
	}

}