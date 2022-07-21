#include <bits/stdc++.h>
#include <vector>
using namespace std;
int solve(vector<int>arr,int k)
{
	int ld=0;
	int rd=0;
   sort(arr.begin(),arr.end());
   for(int i=0;i<arr.size();i++)
   {
   	   ld=arr[arr.size()-1]-arr[i];
   	    if(arr.size()-i==k)
   	    {
   	    	break;
   	    }
   }
   for (int i = arr.size()-1; i>=0 ;i--)
   {
   	   rd=arr[i]-arr[0];
   	    if(arr.size()-i==k)
   	    	break;
   }
  return min(ld,rd);
}
int main()
{
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int k;
 	cin>>k;
    cout<<	solve(arr,k);
}