#include<bits/stdc++.h>
using namespace std;
bool check(int arr[],int n,int f)
{
	if(arr[0]==f)
	{
		return true;
	}
	else return false;
	 int x=check(arr+1,n-1,f);
	return x;
	 //

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
	int y =check(arr,n,f);
	if(y==1)
	{

		cou<<'true';
	}
	else cout<<"false";
	

}
