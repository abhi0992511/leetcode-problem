#include <bits/stdc++.h>
using namespace std;
bool is_prime(long long ans)
{
	if(ans<=1)
		return false;
	for(long long i=2;i<=ans;i++)
	{
		if(ans%i==0)
			return false;
	}
	return true;
}
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
   long long ans=a*b*c+d;
   if(ans%2==0)
   	   cout<<"none";
   	else
  {
  	 if(is_prime(ans))
   	  cout<<"none";
   	else
   		cout<<ans;
  }

}