#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int ans=0;
	int temp=0;
	cin>>n;
	int *a=new int [n];
	int *b=new int[n];
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin>>b[i];
	}
	for(int j=0;j<n;j++)
	{
     
        int index=b[j];
       for (int k = 1; k<n; k++)
       {
       	 if(b[j]==b[k]) 
       	 {
            if(a[j]<a[k])
            {
              temp=a[j];
            }
       	 }
       }
       ans=ans+a[j]+temp;
	}
	cout <<ans;
		
}