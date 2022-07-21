#include <bits/stdc++.h>
#include <queue>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int>a(n);
	queue<int>p;
	priority_queue<int>pq;
	for (int i = 0; i <n; ++i)
	{
		cin>>a[i];
		p.push(a[i]);
	}
	int index;
	cin>>index;
	for (int i = 0; i < a.size(); ++i)
	{
		pq.push(a[i]);
	}
	int count=0;
	for (int i = 0; i < p.size(); ++i)
	{
		if (p.front()==pq.top())
		{   
			
			if (a[index]==p.front())
			{
				p.pop();
			pq.pop();
			count++;
			}
			else{
				p.pop();
			pq.pop();
			count++;
			}
			
		}
		else
		{
          int x=p.front();
          p.pop();
          p.push(x);
          
		}
	}
	cout<<count;


	
}