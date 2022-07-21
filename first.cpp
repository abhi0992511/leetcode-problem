#include <bits/stdc++.h>
using namespace std;
int first(int arr[],int n,int f)
{
   if(n==0)
	{
		return -1;

	}
	if(arr[0]==f)
	{
		return 0;

	}
	int ans=first(arr+1,n-1,f);
	if(ans==-1)
	{
		return -1;

	}
	else
		return ans+1;




}
int main()
{
	int n,f;
cout<<"enter the length of array";

cin>>n;
int *arr=new int [n];
//int ** start=arr;
cout<<"enter the value in array";
for (int i = 0; i <n; i++)
{
	cin>>arr[i];
}
cout<<"Number to be find";
cin>>f;
int index=first(arr,n,f);
cout<<index;
delete []arr;

}