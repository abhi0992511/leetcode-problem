#include <bits/stdc++.h>
#include <vector>
using namespace std;
int lds(vector<int>a)
{
	int m=a.size();
	vector<int>op(m);
	 op[0]=1;
	// for(int i=1;i<m;i++)
	// {
	// 	op[i]=1;
	// 	for(int j=i-1;j>=0;j--)
	// 	{
	// 		if(a[j]<a[i]&&op[i]<op[j]+1)
	// 			op[i]=op[j]+1;
	// 	}
	// }
	 //nnby reverse:
	  for(int i=m-1;i>=0;i--)
        {
            op[i]=1;
            for(int j=i+1;j<m;j++)
            {
                if(a[j]<a[i]&&op[i]<op[j]+1)
                {
                    op[i]=op[j]+1;
            
                }
            }
        }
	int best=0;
	for (int i = 0; i < m; ++i)
	{
		best=max(best,op[i]);
	}
	return  best;


}
int main()
{
	int n;
	cin>>n;
	vector<int>a(n);
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	cout<<lds(a);
}