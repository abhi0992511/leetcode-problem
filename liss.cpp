#include <bits/stdc++.h>
using namespace std;



//LIS:
int lis(int *in,int n)
{
	int *op=new int[n];
	op[0]=1;
	for (int i = 1; i < n; ++i)
	{
		op[i]=1;
		for(int j=i-1;j>=0;j--)
		{
			if (in[j]>in[i])
			{
				continue;
			}
			int pos=op[j]+1;
			if (pos>op[i])
			{
				op[i]=pos;
			}
		}
	}
	int best=0;
	for (int i = 0; i < n; ++i)
	{
		if (op[i]>best)
		{
			best=op[i];
		}
	}
	delete []op;
	return best;
}
int main()
{
	int n;
	cin>>n;
	int *in=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>in[i];
	}
	int x=lis(in,n);
	cout<<x;
	delete []in;
}