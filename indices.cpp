#include<bits/stdc++.h>
using namespace std;
int indce(int arr[],int n int f)
{
	if(n==0)
		{
			return 0;

		}
	int ans=indce(arr,n-1,f);
	if(arr[n]==f)
	{

	}


}
int main()
{
int n,f;
	cout<<"Enter the size";
	cin>>n;

	int * arr= new int [n];
	for(int i=0;i<n;i+=1)
	{
		cin>>arr[i];

	}
	cout<<"Enter the no to find";
	cin>>f;	
	int x=indce(arr,n,f);
}