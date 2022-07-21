#include<bits/stdc++.h>
using namespace std;
 int zeros(int n)
{
   // if(n==0)
   // {
   // 	return 0;
   // }
   // else
   // {
   // 	int d=n%10;
   // if(d==0)
   // {
   // 	return zeros(n/10)+1;
   // }
   // else
   // 	return zeros(n/10);
   // }
	static int count=0;
	if(n==0)
		return 1;
	if(n>0)
	{
		if(n%10==0)
		{
			count++;
			
		}
		zeros(n/10);
		
	}
	return count;
}
int main()
{
	int n;
	cout<<"enter a no";
	cin>>n;
	int count=zeros(n);
	cout<<count;
}