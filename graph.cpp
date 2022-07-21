#include <bits/stdc++.h>
using namespace std;
void dfs(int i,vector<int>graph[],vector<bool>&visted,vector<int>&sol)
{
   visted[i]=true;
   sol.push_back(i);
   for(auto j:graph[i])
   {  if(!visted[j])
   	   dfs(j,graph,visted,sol);
   }
}
vector<int>bfs(vector<int>graph[],int n)
{
	vector<int>ans;
	vector<bool>visit(n+1,false);
	
	for(int i=1;i<=n;i++)
	{
		if(!visit[i])
		{
			queue<int>pq;
			pq.push(i);
			visit[i]=true;
			
			while(!pq.empty())
			{
				int node=pq.front();
				pq.pop();
				ans.push_back(node);
				for(auto j:graph[node])
				{
					if(!visit[j])
					{
						visit[j]=true;
						ans.push_back(j);
					}
				}
			}
		}
	}
	return ans;
}
void print(vector<int>graph[],int m)
{
	
	for(int i=0;i<m;i++)
	{
		cout<<i<<"->";
		for(auto it:graph[i])
		{
			cout<<it<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>graph[n+1];
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	print(graph,m);
	vector<bool>visted(n+1,false);
	vector<int>sol;
	for(int i=1;i<=n;i++)
	{
		if (!visted[i])
		{
			dfs(i,graph,visted,sol);
		}
	}
	vector<int>res=bfs(graph,n);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
	cout<<endl;
	for(int i=0;i<res.size();i++)
		cout<<sol[i]<<" ";
}