#include<bits/stdc++.h>
using namespace std;
// int maxe(int *a,n)
// {
// 	int ans=INT_MIN;
// 	for(int i=0;i<n;i+2)
// 	{
// 		if (a[i]>ans)
// 		{
// 			ans=a[i];
// 		}
// 	}
// 	return ans;
// }
// // int maxo(int *a,n)
// {
// 	int ans=INT_MIN;
// 	for(int i=1;i<n;i+2)
// 	{
// 		if (a[i]>ans)
// 		{
// 			ans=a[i];
// 		}
// 	}
// 	return ans;
// }
int main()
{
// 	// int n;
// 	// int m;
// 	// int s1=0;
// 	// int s2=0;
// 	// cin>>n>>m;
// 	// for (int i = 1; i <=m; i++)
// 	// {
// 	// 	if (i%n==0)
// 	// 	{
// 	// 		s1=s1+i;
// 	// 	}
// 	// 	else
// 	// 	s2=s2+i;
// 	// }
// 	// cout<<abs(s1-s2);
// int n;
// cin>>n;
// int *a=new int[n];
// for(int i=0;i<n;i++)
// {
// 	cin>>a[i];
// }
	int n,m;
	cin>>n>>m;
	int count=0;
	int max=0;
	for (int i = n; i<=m; i++)
	{

      while(i>=0)
      {
      	if (i%2==0)
      	{
      		count=count+1;
      		i=i/2;
      	}
      	else{
      		break;
      	}
      }
      if (count>max)
      {
      	max=count;
      }





		}
		cout<<max;


}