#include <bits/stdc++.h>
using namespace std;
//USING_RECURSION:
int step(int n)
{
	if(n==0||n==1)
		return 1;
	if (n==2)
	{
		return 2;
	}
	return step(n-3)
+step(n-2)
+step(n-1);


}
//USING_DP:
int step1(int n)
{
	int *a=new int[n+1];
	a[0]=1;
	a[1]=1;
	a[2]=2;
	for (int i = 3; i < n+1; i++)
	{
		a[i]=a[i-1]+a[i-2]+a[i-3];

	}
	return a[n];
}
//USING_MEMORIASATION:
int step_helper(int n,int *ans)
{
	if(n==0||n==1)
		return 1;
	if (n==2)
	{
		return 2;

	}
	if (ans[n]!=-1)
	{
		return ans[n];
	}
	ans[n]=step_helper(n-3,ans)+step_helper(n-2,ans)+step_helper(n-1,ans);
	return ans[n];
}
int step3(int n)
{
	int *ans=new int [n+1];
	for (int i = 0; i < n+1; ++i)
	{
		ans[i]=-1;
	}
	return step_helper(n,ans);
}


	int main()
	{
	int n;
	cout<<"enter the no step";
	cin>>n;
	int s=step3(n);
	cout<<s;
}