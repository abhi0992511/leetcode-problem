#include<bits/stdc++.h>
#include <vector>
using namespace std;
bool max_heap(vector<int>&a)
{
	for (int i = 0; i <=(a.size()-1)/2; i++)
	{
		int parentindex=i;
		int lc=i*2+1;
		int rc=i*2+2;
		// if ( ||a[parentindex]<a[rc])
		// {
		// return false;
		// }
		if (a[parentindex]<a[lc])
		{
			return false;
		}
		if (rc<a.size()&&a[parentindex]<a[rc])
		{
		    return false;
		}
	}
	return true;
}
int main()
{
	int n;
	cin>>n;
	vector<int>a(n);
	for (int i = 0; i < a.size(); ++i)
	{
		cin>>a[i];
	}
   cout<<max_heap(a);

}