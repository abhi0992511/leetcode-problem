#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
//RECURSIVE _METHOD:
int reduce(int n)
{ 
	
	if(n==1)
		return 0;
	int x=reduce(n-1);
	int y=INT_MAX;
	int z=INT_MAX;
	if(n%2==0)
	 y=reduce(n/2);
	if(n%3==0)
	z=reduce(n/3);
	int ans=min(x,min(y,z))+1;
	
	return ans;




}
//USING_DP:
int reduce3(int n)
{
	int*a=new int[n+1];
	if (n<=1)
	{
		return 0;
	}
	
	a[0]=INT_MAX;
	a[1]=0;
	a[2]=1;
	a[3]=1;
	for (int i = 4; i < n+1; i++)
	{
		int x=i-1;
		int y=0;
		int z=0;
		if (i%2==0)
		{
			y=i/2;
		}
		if (i%3==0)
		{
			z=i/3;
		}
		a[i]=min(a[x],min(a[y],a[z]))+1;
	}

	return a[n];

}
//USING_MEMORISATION:
int reduce_helper(int n,int*ans)
{
	if (n<=1)
	{
		return 0;
	}
	int x;
	if(ans[n-1]!=-1)
		x=ans[n-1];
	else
		x=reduce_helper(n-1,ans);
	int y=INT_MAX;
	int z=INT_MAX;
	if (n%2==0)
	{
	   if(ans[n/2]!=-1)
	     y=ans[n/2];
	 else
	 	y=reduce_helper(n/2,ans);

	}
	if (n%3==0)
	{
		if(ans[n/3]!=-1)
			z=ans[n/3];
		else
			z=reduce_helper(n/3,ans);
	}
	int a=min(x,min(y,z))+1;
	ans[n]=a;
	return a;

}
int reduce2(int n)
{
	int *ans=new int[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		ans[i]=-1;
	}
	reduce_helper(n,ans);
}
int main()
{
	int n;
	cin>>n;
     int count=0;
     int res=INT_MAX;
      
    cout<< reduce3(n)<<endl;
    cout<<reduce2(n)<<endl;
    cout<<reduce(n)<<endl;
   

}