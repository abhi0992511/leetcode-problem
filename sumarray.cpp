#include <bits/stdc++.h>
using namespace std;
int sum(int arr[],int n)
{
	if(n==0)
	{
		return 0;

	}
	// if(n==1)
	// {
	// 	return ;
	// }
	int y=sum(arr,n-1);
	return y + arr[n-1];
}
int main()
{
int n;
cout<<"enter the length of array";

cin>>n;
int *arr=new int [n];
cout<<"enter the value in array";
for (int i = 0; i <n; i++)
{
	cin>>arr[i];
}
int s=sum(arr,n);
cout<<s;

}