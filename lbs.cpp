#include <bits/stdc++.h>
using namespace std;
// int lbs(int *a,int n)
// {
// 	if (n==1)
// 	{
// 		return 1;
// 	}
// 	// if (a[0]<a[1])
// 	// {
// 	// 	return 0;
// 	// }
// 	int *ans=new int[n];
// 	ans[0]=1;
// 	if (a[0]<a[1])
// 	{
// 		ans[1]=0;
// 	}
// 	else
// 		ans[1]=2;
// 	for (int i = 3; i < n; ++i)
// 	{
// 		if (a[i-1]<a[i]&&i<n&&a[i]<a[i+1])
// 		{
// 			ans[i]=ans[i-1]+1;
// 		}
// 		else if(a[i-1]<a[i]&&i<n&&a[i]>a[i+1])
// 		{
// 			ans[i]=ans[i-1]+1;
// 		}
// 		// else
// 		// {
// 		// 	break;
// 		// }
// 	}
// 	int best=0;
//    for (int i = 0; i < n; ++i)
//    {
//    	if (best<ans[i])
//    	{
//    		best=ans[i];
//    	}
//    }
//    return best;

// }
int lbs(int *a,int n)
{
	//LIS:
	int *ans=new int [n];
	ans[0]=1;
	for (int i = 1; i < n; ++i)
	{
		ans[i]=1;
		for (int j=0;j<i;j++)
		{
			if (a[j]>a[i])
			{
				continue;
			}
			int possible=ans[j]+1;
			if (possible>ans[i])
			{
				ans[i]=possible;
			}
		}
	}
	//LDS:
	int *ans1=new int[n];
	// ans1[n-1]=1;
	// for (int i =n-2; i>=0; i--)
	// {
	// 	a[i]=1;
	// 	for (int j=n-1;j>i;j--)
	// 	{
	// 		if (a[j]>a[i])
	// 		{
	// 			continue;
	// 		}
	// 		int possible2=ans1[j]+1;
	// 		if (possible2>ans1[i])
	// 		{
	// 			ans1[i]=possible2;
	// 		}
	//  	}
	//  }
	for (int i = 0; i < n; ++i)
	{
		ans1[i]=1;
	}
	for (int i = n-2; i >=0; i--)
	{
		for(int j=n-2;j>i;j--)
		{
			if (a[i]>a[j]&&ans1[i]<ans1[j]+1)
			{
				ans1[i]=ans1[j]+1;
			}
		}
	}
	
	int best=0;
	for (int i = 0; i < n; ++i)
	{
		if (best<(ans[i]+ans1[i]-1))
		{
			best=ans[i]+ans1[i]-1;
		}
	}
	return best;
}
int lis(int *a,int n)
{
	int *ans=new int [n];
	ans[0]=1;
	for (int i = 1; i < n; ++i)
	{
		ans[i]=1;
		for (int j=0;j<i;j++)
		{
			if (a[j]>a[i])
			{
				continue;
			}
			int possible=ans[j]+1;
			if (possible>ans[i])
			{
				ans[i]=possible;
			}
		}
	}
}
int lds(int *a,int n)
{
	int *ans1=new int[n];
	ans1[0]=1;
	for (int i = 0; i < n; ++i)
	{
		a[i]=1;
		for (int j=0;j<i;j++)
		{
			if (a[j]<a[i])
			{
				continue;
			}
			int possible2=ans1[j]+1;
			if (possible2>ans1[i])
			{
				ans1[i]=possible2;
			}
		}
	}
}
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cout<<lbs(a,n);
}