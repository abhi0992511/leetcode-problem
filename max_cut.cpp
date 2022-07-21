#include <bits/stdc++.h>
using namespace std;
int max_cut(int n,int a,int b,int c)
{
  if(n==0)
  	return 0;
  int x(INT_MIN),y(INT_MIN),z(INT_MIN);

   if(a<=n)
   x=max_cut(n-a,a,b,c);
   if(b<=n)
    y=max_cut(n-b,a,b,c);
   if(c<=n)
    z=max_cut(n-c,a,b,c);
   return max(x,max(y,z))+1;
}
int main()
{
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	if(n<a&&n<b&&n<c)
		cout<<-1;
	cout<<max_cut(n,a,b,c);

}