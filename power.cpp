#include <bits/stdc++.h>
using namespace std;
int power(int n,int p)
{
	if(p==0)
	{
		return 1 ;

	}
	int y = power(n,p-1);
	return n*y;
}
int main()
{  
   int n, p;
   cin>>n>>p;
   int y=power(n,p);
   cout<<y;


}
