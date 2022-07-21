#include<bits/stdc++.h>
#include "priority_queue.h"
using namespace std;






void heap_sort(vector<int>&ans);
{
  for (int i = 1; i < ans.size(); i++)
  {  
    int childindex=i;
    
     
     while(childindex>0)
         
     {
        int parentindex=(i-1)/2;
        if (ans[childindex]<ans[parentindex])
        {
            int temp=ans[parentindex];
            ans[parentindex]=ans[childindex];
            ans[childindex]=temp;
        }
        else
            break;

       childindex=parentindex;
    


     } 

  }
   int n=ans.size();
    while(n>1)
 {

  int x=ans[0];
  ans[0]=ans[n-1];
  ans[n-1]=x;
  n--;
  int minindex=0;
  int parentindex=0;
  int lc=2*parentindex+1;
  int rc=2*parentindex+2;
  while(lc<n)
  {
    if (ans[minindex]>ans[lc])
    {
        minindex=lc;
    }
    if (rc<n&& ans[minindex]>ans[rc])
    {
        minindex=rc;
    }
    if (minindex==parentindex)
    {
        break;
    }
    int temp=ans[minindex];
    ans[minindex]=ans[parentindex];
    ans[parentindex]=temp;
    parentindex=minindex;
     lc=2*parentindex+1;
     rc=2*parentindex+2;
  
    }

  
}
}
int main()
{
	priority_queue1 p;
	p.insert(100);
	p.insert(10);
    p.insert(120);
     p.insert(30);
     cout<<p.getsize()<<endl;
     while(!p.isEmpty())
     	cout<<p.remove_min()<<" ";






}
