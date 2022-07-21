#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>m>>n;
	int **in=new int *[m];
	for (int i = 0; i < m; ++i)
	{
		in[i]=new int[n];
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j=0;j<n;j++)
		{
			cin>>in[i][j];
		}
	}
	int **op=new int *[m];
	for (int i = 0; i < m; ++i)
	{
		op[i]=new int[n];
	}
	for(int j=0;j<n;j++)
	{
		if(in[0][j]==0)
		{
			op[0][j]=1;
		}
		else
			op[0][j]=0;
	}
	for(int i=0;i<m;i++)
	{
		if(in[i][0]==0)
		{
			op[i][0]=1;
		}
		else
			op[i][0]=0;
	}
	for (int i = 1; i < m; ++i)
	{
		for(int j=1;j<n;j++)
		{
			if (in[i][j]!=0)
			{
				op[i][j]=0;
			}
			else
				op[i][j]=min(op[i-1][j-1],min(op[i-1][j],op[i][j-1]))+1;
		}
	}
	int max=0;
	int ans=0;
	for (int i = 0; i < m; ++i)
	{
		for(int j=0;j<n;j++)
		{
			cout<<op[i][j]<<" ";
			ans=ans+op[i][j];
			if(max<op[i][j])
			{
				max=op[i][j];
			}
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<max<<endl;
	cout<<ans;

}