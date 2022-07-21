#include <bits/stdc++.h>
using namespace std;
int last(int arr[],int n,int f)
{
    if(n==0)
    {
    	return -1;
    }
    int ans=last(arr+1,n-1,f);
    if(ans==-1)
    {
    	if (arr[0]==f)
    	{
    		return 0;
    	}
    	else return -1;
    
    }
    return ans+1;
    
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
	int index=last(arr,n,f);
	cout<<index;



}